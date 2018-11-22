# io_tools

Some simple tools for input and output operations

All tools are header only. Add the include directory to your header search path.

## Notes

The stream in the C++ standard library don't support `char8_t`, `char16_t` and `char32_t`!

https://stackoverflow.com/questions/8168997/using-char16-t-and-char32-t-in-i-o

We don't use `wchar_t` in our code. Because of that **we support `char` only** in the io_tools library functions.

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

#### C-Arrays and `std::array` (C++11)

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

#### `std::vector`  (C++11)

For both input and output streams the I/O operators are overloaded. In include `io_tools/io_std_vector.hpp`.

Array format as string is: `'{' element *(',' element) '}'`.

The `std::vector` size is automatically adjusted during the input operation.

Then you need to import the overloads into your scope:

```cpp
using namespace ::io_tools::io_std_vector;
```

##### Example C-Array I/O

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

#### `name_generator`

This tool is not well designed and should be replaced by a better one.

Don't use it!
