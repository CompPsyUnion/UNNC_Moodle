DROP TABLE IF EXISTS Grade; -- Consider, why do we drop the Grade table first?
DROP TABLE IF EXISTS Module;
DROP TABLE IF EXISTS Student;

CREATE TABLE Student(
    sID INTEGER PRIMARY KEY,
    firstName VARCHAR(20) NOT NULL,
    lastName VARCHAR(20) NOT NULL
);

CREATE TABLE Module(
    mCode CHAR(8) PRIMARY KEY,
    title VARCHAR(30) NOT NULL,
    credits INTEGER NOT NULL
);

CREATE TABLE Grade(
    sID INTEGER NOT NULL,
    mCode CHAR(8) NOT NULL,
    grade INTEGER NOT NULL,
    PRIMARY KEY (sID, mCode),
    FOREIGN KEY (sID)
        REFERENCES Student(sID),
    FOREIGN KEY (mCode) 
        REFERENCES Module(mCode)
);

INSERT INTO Student VALUES  (1, 'John', 'Smith'), 
                            (2, 'Jane', 'Doe'), 
                            (3, 'Mary', 'Jones'),
                            (4, 'David', 'Smith');

INSERT INTO Module VALUES   ('COMP1036', 'Fundamentals', 20),
                            ('COMP1048', 'Databases', 10),
                            ('COMP1038', 'Programming', 20);

INSERT INTO Grade VALUES    (1, 'COMP1036', 35),
                            (1, 'COMP1048', 50),
                            (2, 'COMP1048', 65),
                            (2, 'COMP1038', 70),
                            (3, 'COMP1036', 35),
                            (3, 'COMP1038', 65);