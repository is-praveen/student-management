
# Student Record Management System

This project is a simple C-based Student Record Management System that allows users to add and manage student data, such as ID, name, class, and mobile number. The data is stored in a file (`record.txt`) to retain the records across sessions.

## Features
- Add a new student record with details like ID, name, class, and mobile number.
- Store data in a text file (`record.txt`) for persistence.

## Contributing
### Suggested Improvements
1. **Error Handling**: Enhance error handling across functions, especially in fopen and fclose, to ensure robust file management.
2. **Memory Safety**: Improve string handling in functions using fgets to prevent buffer overflow risks.
3. **Unimplemented Functionality**: Implement the deleteByID function for removing student records by ID.
4. **Input Validation**: Add validations to user inputs for menu options and other entries to prevent invalid data entry.
5. **File Structure Consistency**: Adopt a standard format for storing records in record.txt (e.g., comma-separated or tab-separated values).
6. **Code Refactoring**: Break down large functions, add comments, and document the purpose of each function.
### How to Contribute
To contribute to this project, please fork the repository and submit a pull request with clear descriptions of the changes made.
## Files
- `record.c`: Contains the main code for managing student records.
- `record.txt`: The file where student records are stored.

## Usage
### Compilation
To compile the program, use the following command:
```bash
gcc record.c -o record
```

### Running
After compiling, run the executable to start managing records:
```bash
./record
```

### Sample Commands
- The program will prompt you to enter student details. Follow the instructions on the screen.
- The data will be stored in `record.txt`.

## Structure
The main components in the code include:
1. **Struct Definition**: Defines a `Student` struct with fields like `id`, `name`, `className`, and `mobileNumber`.
2. **File Handling**: Records are written to `record.txt`.
3. **Functions**:
   - `addStudent`: Adds a new student record.

## Requirements
- C compiler (e.g., GCC)

## License
This project is for educational purposes and can be freely modified and distributed.
