# Simple Calculator

A simple C based calculator that can perform addition, subtraction, division and multiplication based on a user input.

## Features
1. Interactive Input Handling
  - User Propmt: User can input an arithmetic operation using a specified format.
  - Input Validation: Using a while loop continously prompt the user until a valid input format is provided.
2. Format Checking
  - Custom Format Checking: uses a `format-checker` function to ensure the string follows the "NUM 'OP' NUM" format. The function uses tokenization to verifry correct inputs.

3. String Tokenization and Word Handling
  - String splitting: uses a `divide_string_into_words` to split the input into multiple individual tokens based on delimiters.
  - Dynamic Memory Allocation: Dynamically allocates memories for word handling and potential memory allocation failues, as well as resizing if necessary.
    
4. Basic Arithmetic Operations
 - Program can perform basic sum, multiplication, subtraction, and division.
 - Program can also handle division by zero.

5. Memory Management
  - Clean up: `free_word` function ensures proper deallocation preventing memory leaks.

6. User Feedback
  - Output Display: Program prints the result of arithmetic operation to console
  - Error Handling: If there are issues with input or format, the program displays relevant error messages.

## Future Improvements
1. Add concatenated operations
  - User should be able to do multiple calculations in one line following PEMDAS.
2. Add Modulo Operation
  - User should be able to use '%' operator
