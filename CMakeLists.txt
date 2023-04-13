cmake_minimum_required(VERSION 3.20)
project (CppcheckAndClangTidy)

find_program(CPPCHECK cppcheck REQUIRED)
find_program(CLANG_TIDY clang-tidy REQUIRED)

# Make sure compile_commands.json file is exported
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Uncomment to enable CMake support for Cppcheck and Clang-Tidy - analysis will be performed alongisde build
# set(CMAKE_CXX_CPPCHECK "cppcheck;--project=compile_commands.json;--enable=all")
# set(CMAKE_CXX_CLANG_TIDY  "clang-tidy;-p=${CMAKE_CURRENT_BINARY_DIR};-checks=-*,modernize-*,bugprone-*")

# Recurse into the "app", "libthirdparty" and "libmath" subdirectories. This does not actually cause another cmake executable to run - same process will walk through the project's entire directory structure.
add_subdirectory (app)
add_subdirectory (libmath)
add_subdirectory (libthirdparty)

# Cppcheck target 
#       NOTE: To suppress warnings from 3rd party add argument: "--suppress=*:*libthirdparty\*", the syntax is --suppress=[error_id]:[filename]:[line]
add_custom_target(cppcheck-check COMMAND cppcheck --project=compile_commands.json --enable=all --error-exitcode=1)

# Clang-Tidy target 
file(GLOB_RECURSE ALL_SOURCES "*.hpp" "*.cpp")
list(FILTER ALL_SOURCES EXCLUDE REGEX ${CMAKE_CURRENT_BINARY_DIR})
#       NOTE: To suppress warnings from 3rd party add below: "list(FILTER ALL_SOURCES EXCLUDE REGEX "libthirdparty/")"

add_custom_target(clang-tidy-check COMMAND clang-tidy ${ALL_SOURCES} -p=${CMAKE_CURRENT_BINARY_DIR} -checks=-*,modernize-*,bugprone-* -warnings-as-errors=*)
