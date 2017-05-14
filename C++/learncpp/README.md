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

## Chapter 2
Fundamental Data Types:

| Category       | Type        | Minimum Size |
| -------------- | ----------- | ------------ |
| boolean        | bool        | 1 byte       |
| character      | char        | 1 byte       |
|                | wchar_t     | 1 byte       |
|                | char16_t    | 2 bytes      |
|                | char32_t    | 4 bytes      |
| floating point | float       | 4 bytes      |
|                | double      | 8 bytes      |
|                | long double | 8 bytes      |
| integer        | short       | 2 bytes      |
|                | int         | 2 bytes      |
|                | long        | 4 bytes      |
|                | long long   | 8 bytes      |
| void           | no type     | -            |

- variable initialization
  - copy initialization: `int nValue = 5;`
  - direct initialization: `int nValue(5);`
    - favored over copy initialization
  - uniform initialization in C++11: `int value{5};` or `int value{} // default initialization`
    - disallowing "narrowing" type conversions
- variable assignment
  - copy assignment
- integers
  - signed integer can hold both positive and negative numbers
    - `signed int i`
  - unsigned integer can only hold positive values
    - `unsigned int i`
  - all integer variables except char are signed by default
  - C++ only guarantees that integer variables will have a minimum size, but can be larger depending on target system

Fixed Width Integers (found in cstdint)

| Name | Type | Range | Notes |
| ---- | ---- | ----- | ----- |
| int8_t | 1 byte signed | -128 to 127 | treated like a signed char on many systems |
| uint8_t | 1 byte unsigned | 0 to 255 | treated like an unsigned char on many systems |
| int16_t | 2 byte signed | -32,768 to 32,767 | |
| uint16_t | 2 byte unsigned | 0 to 65,535 | |
| int32_t | 4 byte signed | | |
| uint32_t | 4 byte unsigned | | |
| int64_t | 8 byte signed | | |
| uint64_t | 8 byte unsigned | | |

- floating point numbers
  - always signed
  - f suffix means float and not double (double by default)
  - std::cout has a default precision of 6
    - override by using `std::setprecision()` function defined in a header file called iomanip
  - in C++, 87 and 87.000 are treated as exactly the same
  - rounding errors b/c of the differences between binary and decimal numbers (esp fractions)
  - `INF` - infinity
  - `NaN` - "Not a Number"
  - `IND` - indeterminate
- boolean values
  - true evaluates to the integer 1, false evaluates to the integer 0
    - use `std::boolalpha` to print booleans as true/false instead of 1/0; `std::noboolalpha` to turn off
- characters
  - can initialize with both integer value and the character
  - static cast - between fundamental data types
    - `static_cast<new_type>(expression)`
- literals - values inserted directly into the code
  - string literals are weird
- constants - add const before or after type (before type is better)
  - `const double gravity { 9.8 }`
  - must be initialized at declaration
  - runtime constant - initialization values can only be resolved at runtime
  - compile-time constants - initialization values resolved at compile-time
  - some cases where C++ requires a compile-time constant instead of a run-time constant -> `constexpr` ensures that the constant must be a compile-time constant
  - avoid using #define to create symbolic constants
    - create a header file to hold constants
    - inside header file, declare a namespace
    - add all constants inside namespace
    - #include header file whenever you need it
    - use `::` to access constants in .cpp files
