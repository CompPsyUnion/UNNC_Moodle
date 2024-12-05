#include <stdio.h>

void updatemap(char a[8][10],int x, int y);
void printmap(char a[8][10]);

int main(int argc, char *argv[])
{
  char map[8][10];
 
  int i,j;
  int posix=4, posiy=1;

  for(i=0;i<10;i++)
    {
      map[0][i]='#';
      map[7][i]='#';
    }
 
  for(i=0;i<8;i++)
    {
      map[i][0]='#';
      map[i][9]='#';
    }

  for(i=1;i<=6;i++)
    {
      for(j=1;j<=8;j++)
	map[i][j]='.';
    }
  map[posiy][posix]='@';
  printmap(map);

  printf("Enter a command and press return.\n");
  printf("If entering '8', the @ char moves 1 step up\n");
printf("If entering '2', the @ char moves 1 step down\n");
printf("If entering '4', the @ char moves 1 step left\n");
printf("If entering '6', the @ char moves 1 step right\n");
printf("If entering '0', the program exits\n");

 int value=1;
 int control;
 while(value>0)
   {
     scanf("%d",&control);

     switch(control)
       {
       case 8:
	 if(posiy>1)
	   {  posiy--;
	     updatemap(map,posix,posiy);
	     printmap(map);
	   }
	 else
	   printf("Invalid move!\n");
	 break;
      
       case 2:
	 if(posiy<6)
	   {  posiy++;
	     updatemap(map,posix,posiy);
	     printmap(map);
	   }
	 else
	   printf("Invalid move!\n");
	 break;
       
       case 4:
	 if(posix>1)
	   { posix--;
	     updatemap(map,posix,posiy);
	     printmap(map);
	   }
	 else
	   printf("Invalid move!\n");
	 break;
       
       case 6:
	 if(posix<8)
	   { posix++;
	     updatemap(map,posix,posiy);
	     printmap(map);
	   }
	 else
	   printf("Invalid move!\n");
	 break;

       case 0:
	 value=0;
	 break;

       default:
	 printf("Invalid movev!\n");
	 break;
       }
   }

}



void updatemap(char a[8][10],int x, int y)
{
  int i,j;  
  for(i=1;i<=6;i++)
    {
      for(j=1;j<=8;j++)
	a[i][j]='.';
    }
  a[y][x]='@';
  
}

void printmap(char a[8][10])
{
  int i,j;
  for(i=0;i<8;i++)
    {
      for(j=0;j<10;j++)
	printf("%c",a[i][j]);
      printf("\n");
    }

}
