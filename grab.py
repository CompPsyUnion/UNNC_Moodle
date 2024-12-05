import requests
import urllib3
from bs4 import BeautifulSoup
from dotenv import load_dotenv
from urllib.parse import unquote, urljoin, urlparse, urlunparse, parse_qs, urlencode
import os
import re
from url import url_list

urllib3.disable_warnings(urllib3.exceptions.InsecureRequestWarning)

def authenticate(session, url_login, username, password):
    response = session.get(url_login, verify=False, timeout=10)
    soup = BeautifulSoup(response.text, 'html.parser')
    logintoken = soup.find('input', {'name': 'logintoken'})['value']

    login_payload = {
        'username': username,
        'password': password,
        'logintoken': logintoken
    }

    response = session.post(url_login, data=login_payload, verify=False, timeout=10)
    if response.url != url_login:
        print('登录成功')
        print('Cookies:', session.cookies.get_dict())
        return True
    else:
        print('登录失败')
        return False

def download_file(session, file_url, folder_name):
    parsed_url = urlparse(file_url)
    query_params = parse_qs(parsed_url.query)
    query_params.pop('_forcedownload', None)
    new_query = urlencode(query_params, doseq=True)
    new_url = urlunparse(parsed_url._replace(query=new_query))
    file_url = unquote(new_url)

    file_name = re.sub(r'[\\/*?:"<>|]', '_', file_url.split('/')[-1])
    file_name = file_name.replace('_forcedownload=1', '')
    file_name = re.sub(r'_time=\d+', '', file_name)

    file_path = os.path.join(folder_name, file_name)
    if os.path.exists(file_path):
        print(f'Skipping already downloaded file: {file_name}')
        return

    with session.get(file_url, stream=True, verify=False, timeout=10) as r:
        r.raise_for_status()
        with open(file_path, 'wb') as f:
            for chunk in r.iter_content(chunk_size=8192):
                f.write(chunk)

    print(f'Downloaded {file_name} to {folder_name}')

def process_course_page(session, course_page_url, label):
    course_page = session.get(course_page_url, verify=False, timeout=10)
    course_page.raise_for_status()

    folder_name = label
    if not os.path.exists(folder_name):
        os.makedirs(folder_name)

    soup = BeautifulSoup(course_page.text, 'html.parser')

# 类型一
    folder_name = label
    links = re.findall(r'href="(https?://moodle\.nottingham\.ac\.uk/mod/folder/view\.php\?id=[^"]+)"', course_page.text)
    for link in links:
        folder_page = session.get(link, verify=False, timeout=10)
        folder_page.raise_for_status()
        folder_soup = BeautifulSoup(folder_page.text, 'html.parser')
        folder_name = os.path.join(label, re.sub(r'[\\/*?:"<>|]', '_', folder_soup.find('div', class_='page-header-headings').find('h1').text))

        if not os.path.exists(folder_name):
            os.makedirs(folder_name)

        file_links = folder_soup.find_all('a', href=True)
        for file_link in file_links:
            file_url = file_link['href']
            if not re.match(r'https://moodle\.nottingham\.ac\.uk/pluginfile\.php/[^"]+', file_url):
                continue
            if not urlparse(file_url).scheme:
                file_url = urljoin(link, file_url)
            if file_url.lower().endswith(('.png', '.jpg', '.jpeg', '.gif', '.bmp', '.svg')):
                continue

            download_file(session, file_url, folder_name)
# 类型二
    folder_name = label
    links = re.findall(r'href="(https?://moodle\.nottingham\.ac\.uk/pluginfile\.php/[^"]+)"', course_page.text)
    for link in links:
        if link.lower().endswith(('.png', '.jpg', '.jpeg', '.gif', '.bmp', '.svg')):
            continue
        download_file(session, link, folder_name)
# 类型三
    folder_name = label
    activities = soup.find_all('li', class_=['activity activity-wrapper resource modtype_resource', 'activity activity-wrapper resource modtype_resource indented'])
    for activity in activities:
        if 'indented' not in activity['class']:
            activity_name = activity.find('div', class_='activity-item')['data-activityname']
            folder_name = os.path.join(label, re.sub(r'[\\/*?:"<>|]', '_', activity_name))

            if not os.path.exists(folder_name):
                os.makedirs(folder_name)

        links = re.findall(r'href="(https?://moodle\.nottingham\.ac\.uk/pluginfile\.php/[^"]+)"', str(activity))
        redirect_links = re.findall(r'href="(https?://moodle\.nottingham\.ac\.uk/mod/resource/view\.php\?id=[^"]+)"', str(activity))

        for redirect_link in redirect_links:
            redirect_page = session.get(redirect_link, verify=False, timeout=10)
            redirect_page.raise_for_status()
            links += re.findall(r'href="(https?://moodle\.nottingham\.ac\.uk/pluginfile\.php/[^"]+)"', redirect_page.text)

        for link in links:
            if link.lower().endswith(('.png', '.jpg', '.jpeg', '.gif', '.bmp', '.svg')):
                continue
            download_file(session, link, folder_name)

def main():
    load_dotenv()
    username = os.getenv('MOODLE_USERNAME')
    password = os.getenv('MOODLE_PASSWORD')
    session = requests.Session()
    url_login = 'https://moodle.nottingham.ac.uk/login/index.php'
    session.verify = False

    if not authenticate(session, url_login, username, password):
        exit()

    for course in url_list:
        process_course_page(session, course['url'], course['label'])

if __name__ == "__main__":
    main()