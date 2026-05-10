*This project has been created as part of the 42 curriculum by yusakaki*

# ft_printf

## Description

`ft_printf` is a recreation of the standard C library function `printf()`. The goal of this project is to implement a variadic function that mimics the behavior of the original `printf()` from libc.

This project teaches fundamental concepts including:
- Variadic functions (functions with variable number of arguments)
- Format string parsing
- Type conversions and output formatting
- Memory management and proper resource handling
- Well-structured and extensible code design

## Instructions

### Compilation

To compile the project and generate the library archive:

```bash
make
```

This will create `libftprintf.a` at the root of the repository.

### Available Targets

- `make` or `make all` - Compile the library
- `make clean` - Remove object files
- `make fclean` - Remove object files and the library
- `make re` - Recompile everything from scratch

### Usage

Include the header file in your C source:

```c
#include "ft_printf.h"
```

Link the library when compiling your program:

```bash
gcc -Wall -Wextra -Werror your_program.c libftprintf.a -o your_program
```

Use the function like the standard `printf()`:

```c
ft_printf("Hello %s, you have %d points!\n", "user", 42);
```

## Supported Conversions

The implementation supports the following format specifiers:

| Specifier | Description |
|-----------|-------------|
| `%c` | Prints a single character |
| `%s` | Prints a string |
| `%p` | Prints a void* pointer in hexadecimal format |
| `%d` | Prints a decimal (base 10) integer |
| `%i` | Prints an integer in base 10 |
| `%u` | Prints an unsigned decimal (base 10) integer |
| `%x` | Prints a number in hexadecimal (base 16) lowercase format |
| `%X` | Prints a number in hexadecimal (base 16) uppercase format |
| `%%` | Prints a percent sign |

## Algorithm and Data Structure

### Approach

The implementation uses a straightforward parsing approach:

1. **Format String Parsing**: The function iterates through the format string character by character
2. **Conversion Detection**: When a `%` is encountered, the next character determines which conversion handler to call
3. **Handler Dispatch**: A conversion function is called based on the format specifier
4. **Character Counting**: Each helper function returns the number of characters written, allowing for accurate total count

### Key Components

- **Main Parser** (`ft_printf()`): Iterates through the format string and dispatches to appropriate handlers
- **Utility Functions** (`ft_printf_utils.c`): Low-level output functions for writing characters, strings, numbers in various formats
- **Conversion Handlers** (`ft_printf_handlers.c`): Wrapper functions that extract arguments from the variadic argument list and call appropriate utility functions
- **Helper Functions**:
  - `ft_putchar()`: Write a single character
  - `ft_putstr()`: Write a string (handles NULL as "(null)")
  - `ft_putnbr()`: Convert and write signed integers
  - `ft_putunbr()`: Convert and write unsigned integers
  - `ft_puthex()`: Convert and write hexadecimal numbers
  - `ft_putptr()`: Convert and write pointers

### Design Benefits

- **Extensibility**: New format specifiers can be added by creating new handler functions
- **Modularity**: Each conversion type is separated into its own handler function
- **Simplicity**: Recursive implementations for number conversion avoid buffer management
- **Standards Compliance**: Follows the 42 School Norm coding standards

## Limitations

- No buffer management is implemented (as per project requirements)
- No support for flags, width, or precision modifiers
- Return value represents character count, which may differ slightly from original `printf()` in edge cases

## Resources

### C Standard Library Documentation
- [printf man page](https://man7.org/linux/man-pages/man3/printf.3.html)
- [C Standard - printf specification](https://en.cppreference.com/w/c/io/fprintf)

### Variadic Functions
- [stdarg.h documentation](https://man7.org/linux/man-pages/man3/stdarg.3.html)
- [Variadic Functions - C Reference](https://en.cppreference.com/w/c/variadic)

### 42 School Norm
- [42 Norm Documentation](https://github.com/42School/norminette)

## AI Usage

AI tools were not used in the creation of this project. The implementation was developed following standard C practices and the requirements specified in the project subject. All code was written with a focus on understanding variadic functions, format string parsing, and proper memory management principles taught at 42 School.
