# [LearnCpp](www.learncpp.com)

## Chapter 1
- `main()` has return type `int`
  - compiler will automatically specify `return 0` if no return value is specified; however, should always specify `return 0` for good style
  - returning `0` means that all was well
  - if a positive integer is returned, means something went wrong
- keep terminal from closing immediately:
  ```
  std::cin.clear();
  std::cin.ignore(32767, '\n');
  std::cin.get();
  ```
- if variable is not initialized, will contain whatever is in the memory location (indeterminate)
- program will compile still if the function parentheses are not added, but what actually happens depends on the compiler
- function parameters: pass by value (like java)
- generally underscores for variables, camel case for functions
- forward declaration
  - compiler reads files sequentially
  - compiler will complain if a function is called before it is defined in the program
  - to fix: either reorder functions or use a forward declaration
    - forward declaration tells compiler about the existence of an identifier before actually defining the identifier
    - function prototype serves as forward declaration for functions
    ```
    int add(int x, int y)
    ```
    - do not need to specify names of parameters, but is helpful for understanding
    - if forward declaration is made but function not called, program will compile and run but then crash at link stage
- in C++, all definitions also serve as declarations
- pure declarations include forward declarations for variables, class declarations, type declarations
- header files
  - consists of a header guard and the actual contents, which should be the declarations for all the functions we want other files to be able to see
  - angled brackets for header files that come with compiler, double quotes for everything else
  - best practices:
    - always include header guards
    - don't define variables in header files unless they are constants
    - do not define functions in header files
    - give header files same name as source files associated with (e.g. `grades.h` go with `grades.cpp`)
  - each .cpp file should explicitly #include all of the header files it needs to compile
  - including header files from other directories: don't include relative path to header, instead tell compiler or IDE by setting an "include path" or "search directory"
    - using g++, can use -I option to specify an alternate include directory
    ```
    g++ -o main -I /source/includes main.cpp
    ```
- directives - specific instructions that start with # and end with a newline
  - includes
  - macro - rule that defines how an input sequence is converted into a replacement output sequence; only cause text substitution for normal code (ignores other preprocessor commands)
    - function-like macros - dangerous
    - object-like macros
      - `#define identifier substitution_text`
        - any further occurrence of `identifier` is replaced by `substitution_text`
        - typically typed in all caps, underscores for spaces
        - shouldn't be used
      - `#define identifier`
        - any further occurrence of the identifier is removed and replaced by nothing
        - macros of this form are generally considered acceptable to use
  - conditional compilation
    - `#ifdef`
      - allows preprocessor to check whether a value has been previously `#defined`. if so, code between the `#ifdef` and the corresponding `#endif` is compiled. otherwise, code ignored
    - `#ifndef`
      - opposite of `#ifdef` - can check whether a value has NOT been previously `#defined`
    - `#endif`
