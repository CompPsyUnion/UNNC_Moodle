-- The following improves the formatting of the output we get from SQLite
-- It puts all our data into "columns", ensuring that things align.
-- Note, sometimes, this will mean our data gets truncated (cut-off) so that it "fits"
-- within a column.
.mode columns

-- Dropping tables if they exists
DROP TABLE IF EXISTS Enrolment;
DROP TABLE IF EXISTS Student;
DROP TABLE IF EXISTS Module;

-- Create the Student Table
CREATE TABLE Student ( 
    sID INTEGER PRIMARY KEY, 
    sName VARCHAR(50) NOT NULL, 
    sAddress VARCHAR(255), 
    sYear INTEGER DEFAULT 1 
);

-- Create the Module Table
CREATE TABLE Module (
    mCode CHAR(8) PRIMARY KEY,
    mTitle VARCHAR(100) NOT NULL,
    mCredits INTEGER NOT NULL DEFAULT 10
);

-- Create the Enrolment Table with Foreign Keys
CREATE TABLE Enrolment (
    sID INTEGER NOT NULL,
    mCode CHAR(8) NOT NULL,
    PRIMARY KEY (sID, mCode),
    FOREIGN KEY (sID) REFERENCES Student(sID), -- Links Enrolment.sID to Student.sID
    FOREIGN KEY (mCode) REFERENCES Module(mCode) -- Links Enrolment.mCode to Module.mCode
);

-- Inserting sample data into Student Table
INSERT INTO Student (sID, sName, sAddress, sYear) VALUES
    (1, 'John Smith', '123 Main St', 1),
    (2, 'Jane Doe', '456 Elm St', 2);

-- Inserting sample data into Module Table
INSERT INTO Module (mCode, mTitle, mCredits) VALUES
    ('CS101', 'Introduction to Computer Science', 10),
    ('MA101', 'Calculus I', 10);

-- Inserting sample data into Enrolment Table
INSERT INTO Enrolment (sID, mCode) VALUES
    (1, 'CS101'),
    (2, 'MA101');

-- Confirm all the data is there
SELECT * FROM Student;
SELECT * FROM Module;
SELECT * FROM Enrolment;

-- By default, foreign key constraints are not enforced in SQLite
-- We must enable them by running the following. Note this is specific to SQLite, and not a part of the SQL standard.
PRAGMA foreign_keys = ON;

-- Trying to drop the Student Table to demonstrate integrity constraints
-- This should fail since there are foreign key dependencies (in Enrolment)
DROP TABLE Student;

-- If we turn off enforcing foreign_key constraints, then we should be able to drop the student table.
PRAGMA foreign_keys = OFF;
DROP TABLE Student;


-- We can check this has worked by using the SQLite specific command `.tables`.
-- `.tables` simply lists the tables in the current SQLite database.
.tables

