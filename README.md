# io_tools

Some simple tools for input and output operations

All tools are header only. Add the include directory to your header search path.

## Notes

The stream in the C++ standard library don't support `char8_t`, `char16_t` and `char32_t`!

https://stackoverflow.com/questions/8168997/using-char16-t-and-char32-t-in-i-o

We don't use `wchar_t` in our code. Because of that **we support `char` only** in the io_tools library functions.

## Documentation

### Basic input tools

#### C-Array output on streams (C++11)

This dosn't work with arrays of size `0`!

```
using namespace ::io_tools::io_c_array;
```

### I/O for array's

#### C-Arrays and `std::array`

For both input and output stream operators are overloaded. In include `io_tools/io_c_array.hpp`

#include <io_tools/io_c_array.hpp>


### Other

#### `name_generator`

This tool is not well designed and should be replaced by a better one.

Don't use it!
