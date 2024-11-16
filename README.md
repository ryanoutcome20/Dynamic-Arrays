# Dynamic-Arrays

Dynamic-Arrays is a simple lightweight library that brings dynamic array functionality to the C programming language. Simply include the header file ("*dynamic_array.h*"). This was made as a proof of concept to make sure I understood memory management & pointers in C.

## Features
  - **Core Functionality**: Provides operations to add, remove, fetch elements, and get the current size of the array.
  - **Extensible Design**: Future updates will add support for advanced operations and the library is simple to edit and improve.
  - **Ease of Integration**: Designed to easily integrate into existing C projects with minimal setup.

## Getting Started

### Prerequisites

Before you begin, make sure you have the following installed on your system:

- [GCC](https://gcc.gnu.org/) or similar C compiler.

Afterwhich ensure your compiler supports the C99 or newer standard. Use the -std=c99 flag with GCC if needed.

### Installation

1. Cloning the repository:
   ```bash
   git clone https://github.com/ryanoutcome20/Dynamic-Arrays.git
   ```
2. Copy the "*dynamic_array.h*" & "*dynamic_array.c*" file to your working directory.
3. Include the header file in your project:
  ```c
  #include "dynamic_array.h"
  ```

### Usage

For a full usage documentation refer to both the *tests* folder and documentation. Full documentation is auto-generated using [Doxygen](https://www.doxygen.nl/manual/starting.html). See the docs folder or generate it yourself using the provided Doxyfile.

### Contributing

If you find a bug or want to add a new feature, feel free to fork the repository and submit a pull request.

## License

This project is licensed under the GNU General Public License v3.0 - see the [LICENSE](./LICENSE) file for more details.
