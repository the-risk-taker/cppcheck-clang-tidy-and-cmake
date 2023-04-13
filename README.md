# Cppcheck, Clang-Tidy and CMake

## Cppcheck

To use Cppcheck, a static analysis tool for C and C++ code, follow these steps. For basic usage, call it in the project root directory:

```shell
cppcheck --enable=<checks> <path to root directory>

# example:
cppcheck --enable=all .
cppcheck --enable=all -I libmath -I libthirdparty .
```

For analyzing an entire project depending on the compile_commands.json file:

```shell
cppcheck --project=<path to compile_commands.json file> --enable=<checks>

# example:
cppcheck --project=build/compile_commands.json --enable=all 
```

## Clang-Tidy

To use Clang-Tidy, another static analysis tool for C and C++ code, follow these steps. For basic usage on a single file:

```shell
clang-tidy <file to check> -checks=<checks> -- <compilation options>

# example:
clang-tidy app/app.cpp -checks=* -- -I libmath -I libthirdparty
```

For analyzing an entire project depending on the compile_commands.json file:

```shell
clang-tidy [source files to be checked] -p=<path to compilation_commands.json directory> -checks=<checks>

# example:
clang-tidy app/app.cpp libmath/libmath.cpp -p=build -checks=*
```

## Cppcheck and Clang-Tidy via CMake targets

Assuming that Ninja is set as generator (`-G Ninja` CMake option), Cppcheck and Clang-Tidy can be called via:

```shell
# Cppcheck
ninja -C <build_dir> cppcheck-check

# Clang-Tidy
ninja -C <build_dir> clang-tidy-check
```

> NOTE: Additional options can be found in the CMakeLists.txt file.
