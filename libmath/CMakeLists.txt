# Create a library called "libmath" which includes the source file "libmath.cpp". Any number of sources could be listed here.
add_library (libmath libmath.hpp libmath.cpp)

# Make sure the compiler can find include files for our "libmath" library when other libraries or executables link to "libmath"
target_include_directories (libmath PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
