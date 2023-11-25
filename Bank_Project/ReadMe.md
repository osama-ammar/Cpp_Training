# Bank System
----------------
- The main aim from this project is to train on :
    - C++ OOP
    - CMAKE
    - SOLID principles


### Components (classes) :
-----------------------
- Person
    - Cleint 
    - Employee
    - Admin

- DataSourceInterface : (abstract class) control saving , loading and modifying data from text files
    - FileManager : implement DataSourceInterface

- Validations : collections of some general validation methods (check name , passwords ...)
- Parser : to parse data files
- Files Helper : save and get from txt files contains


### TODO :
-----------
- [ ] separating  classes prototypes in header files with basic functionalities
- [x] organizing project files 
- [x] using cmake and making a prelimnary CMakeLists.txt file
- [x] generating txt files for clients info
- [ ] making this files automatically updated with any change in balance
- [ ] making command line interface for the project

