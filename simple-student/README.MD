# Simple Student Database Manager

A simple C-based student database manager reads from a CSV file and stores necessary data on a struct (student).

## Features
1. File I/O Data Management
  - The program reads student data from a CSV file and stores it in a structure.
  - Provides display functionality for student information

2. Dynamic Student Addition
  - New students can be added to the list dynamically using the `addStudent` function

3. File Handling
  - The program demos how to open, read, and close a CSV file
  - Error handling for file operations

4. Structured Data Storage
  - Utilizes a struct for storing data for logical purposes.

5. String Manipulation
  - The program uses functions from the `<string.h>` library to manipulate strings. (i.e. `strcpy` `strcat` `strtok` `strcmp`)

6. Data Parsing
  - The program splits the input line into individual data fields from the CSV file and converts them into usable data types.

7. Scalability
  - The program can handle large amounts of data (students), up to a predefined maximum.

8. Modular Design
  - Code is divided into multiple functions with specific tasks for maintainability and readability purposes.

9. Compatibility
  - Code uses standard C libraries, making it easily portable with some minor changes.

## Future Improvements

1. Command-Line Utility
  - Use of command-line arguments to handle different CSV files or add more functionalities like updating or deleting records

2. Add more functionality 
  - As of now program can only add Students from a predetermined CSV file and display their information. For better purposes, more functions shall be added.

### Bugs

1. Name spacing can cause errors in the storage based on the `read_csv` function logic.
  - for example, a name like Van Der Linde will store Van Der as the full name and shift values towards the right.
