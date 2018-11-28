# io_tools

Some simple tools for input and output operations

All tools are header only. Add the include directory to your header search path.

**Provided C++11 tools**:

- [Input parsing](#basic-stdistream-tools-c11) helpers
- [I/O operator](#io-operators-for-c-arrays-and-stdarray-c11) for C arrays
- [I/O operator](#io-operators-for-c-arrays-and-stdarray-c11) for `std::array`
- [I/O operator](#io-operators-for-stdvector-c11) for `std::vector`
- [Mask all non-printable and non-ascii characters](#mask_non_printstring) in a string

**Provided C++17 tools**:

- Convert [sequences to strings](#range_to_stringsequence-delimiter-c17)
- [Variadic output](#make_stringargs-c17) via `std::ostringstream`
- [Variadic output](#make_string_separated_bydelimiter-args-c17) via `std::ostringstream` with delimiter

## Notes

The stream in the C++ standard library don't support `char8_t`, `char16_t` and `char32_t`!

https://stackoverflow.com/questions/8168997/using-char16-t-and-char32-t-in-i-o

We don't use `wchar_t` in our code. Because of that **we support `char` only** in the io_tools library functions.

## Build and install

The library is header-only but you can install it via `cmake`.

If you wan't to install it for all users:

```
cmake /path/to/io_tools
make
make install
```

If you wan't to install it without root permissions:

```
cmake -DCMAKE_INSTALL_PREFIX=$HOME/.local /path/to/io_tools
make
make install
```

When you installed the library, you can use `find_package(io_tools)` in your `CMakeLists.txt`. It will define `${io_tools_INCLUDE_DIR}` which you can use in `include_directories` to add the installed library to your header search path.

If you installed it with `CMAKE_INSTALL_PREFIX`, you have to use `CMAKE_PREFIX_PATH` by configuring your own project, otherwise `find_package(io_tools)` will not find `io_tools`.

```
cmake -DCMAKE_PREFIX_PATH=$HOME/.local /path/to/your/project
make
```

### Build tests

```
cmake -DIO_TOOLS_BUILD_TESTS=ON /path/to/io_tools
make
```

Instead of `IO_TOOLS_BUILD_TESTS` which builds all tests, you can test for specific C++ standards by:

- `IO_TOOLS_BUILD_TESTS_CPP11`
- `IO_TOOLS_BUILD_TESTS_CPP14`
- `IO_TOOLS_BUILD_TESTS_CPP17`

## Documentation

### Basic `std::istream` tools (C++11)

#### `io_tools::is_next(std::istream& is, char expected)` (C++11)

Returns if the next character in `is` is `expected`. Returns `false` if not `std::ios_base::goodbit` was set in `is`.

The streams `iostate` is never changed by `is_next`!

#### `io_tools::extract_if_is(std::istream& is, char expected)` (C++11)

Same as `io_tools::is_next` but the character is extracted from the stream if it matchs.

#### `io_tools::expect(std::istream& is, T expected)` (C++11)

Same as `io_tools::extract_if_is` but the `std::ios_base::failbit` is set on `is` if extraction failed.

Note that `expected` can be any type with overloaded input operator.

### I/O for sequence types (C++11)

#### I/O operators for C-Arrays and `std::array` (C++11)

This dosn't work with arrays of size `0`!

For both input and output streams the I/O operators are overloaded. In include `io_tools/io_c_array.hpp`/`io_tools/io_std_array.hpp`.

Array format as string is: `'{' element *(',' element) '}'`.

For input operations the element count must match the array size.

Then you need to import the overloads into your scope:

```cpp
using namespace ::io_tools::io_c_array;
using namespace ::io_tools::io_std_array;
```

##### Example C-Array I/O

```cpp
#include <io_tools/io_c_array.hpp>
#include <sstream>

void output_example(){
    using namespace ::io_tools::io_c_array;

    int array[2] = {1, 2};

    std::ostringstream os;
    os << array; // os.str() == "{1,2}"
}

void input_example(){
    using namespace ::io_tools::io_c_array;

    int array[2] = {};

    std::istringstream is("{1,2}");
    is >> array; // array[0] == 1 && array[1] == 2
}
```

##### Example `std::array` I/O

```cpp
#include <io_tools/io_c_array.hpp>
#include <sstream>

void output_example(){
    using namespace ::io_tools::io_std_array;

    std::array< int, 2 > array{{1, 2}};

    std::ostringstream os;
    os << array; // os.str() == "{1,2}"
}

void input_example(){
    using namespace ::io_tools::io_std_array;

    std::array< int, 2 > array{};

    std::istringstream is("{1,2}");
    is >> array; // array[0] == 1 && array[1] == 2
}
```

#### I/O operators for `std::vector` (C++11)

For both input and output streams the I/O operators are overloaded. In include `io_tools/io_std_vector.hpp`.

Array format as string is: `'{' element *(',' element) '}'`.

The `std::vector` size is automatically adjusted during the input operation.

Then you need to import the overloads into your scope:

```cpp
using namespace ::io_tools::io_std_vector;
```

##### Example `std::vector` I/O

```cpp
#include <io_tools/io_std_vector.hpp>
#include <sstream>

void output_example(){
    using namespace ::io_tools::io_std_vector;

    std::vector< int > array{1, 2};

    std::ostringstream os;
    os << array; // os.str() == "{1,2}"
}

void input_example(){
    using namespace ::io_tools::io_std_vector;

    std::vector< int > array;

    std::istringstream is("{1,2}");
    is >> array; // array.size() == 2 && array[0] == 1 && array[1] == 2
}
```

### String creation

#### `range_to_string(sequence, delimiter = ", ")` (C++17)

This tools prints every element of a sequence into a string separated by `delimiter`. A sequence is an object for which you can iterate from begin to end. The print is implemented as output on an `std::ostringstream`.

```cpp
#include <io_tools/range_to_string.hpp>
#include <iostream>
#include <vector>

int main(){
    std::vector< int > s1{1, 2, 3};
    std::cout << range_to_string(s1) << '\n'; // "1, 2, 3"

    int s1[3] = {1, 2, 3};
    std::cout << range_to_string(s2, "x") << '\n'; // "1x2x3"
}
```

#### `make_string(args ...)` (C++17)

Prints every given argument on an `std::ostringstream`. By default `std::boolalpha` is enabled.

```cpp
#include <io_tools/make_string.hpp>
#include <iostream>

int main(){
    std::cout << io_tools::make_string(0,3, "test", 5, '\n'); // "0.3test5\n"
}

```

#### `make_string_separated_by(delimiter, args ...)` (C++17)

Prints every given argument on an `std::ostringstream` separated by `delimiter`. By default `std::boolalpha` is enabled.

```cpp
#include <io_tools/make_string.hpp>
#include <iostream>

int main(){
    std::cout << io_tools::make_string_separated_by(
        "-:-", 0,3, "test", 5, '\n'); // "0.3-:-test-:-5-:-\n"
}

```

### Excape characters to print them in one line

#### `mask_non_print(string)`

This functions replaces any non-printable and non-ascii character in the string with its hex code or escape sequence version. The hex code is in uppercase and starts with `\x`. (E.g. `\x0F`) The following escape sequences are used instead of the hex code: `\a`, `\b`, `\f`, `\n`, `\r`, `\t` and `\v`. Backslashes are replaced by two backslashes. (`\` -> `\\`)

https://en.cppreference.com/w/cpp/language/escape

This is done byte wise and works also for UTF-8 encoded text because UTF-8 encoded characters are required that any byte in the character is bigger then 127 which makes any byte non-ascii.

```cpp
#include <io_tools/mask_non_print.hpp>
#include <iostream>

int main(){
    std::cout << io_tools::mask_non_print("»test«\n"); // "\\xC2\\xBBtest\\xC2\\xAB\\n"
}

```

### Other tools

#### `name_generator`

This tool is not well designed and should be replaced by a better one.

Don't use it!

#### `input_wrapper`

TODO

#### `isubstream`

TODO

#### `substreambuf`

TODO

## License notice

This software was originally developed privately by Benjamin Buch. All changes are released under the Boost Software License - Version 1.0 and published on GitHub.

https://github.com/bebuch/io_tools
