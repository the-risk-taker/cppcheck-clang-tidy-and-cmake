# Create a library called "3rdparty" which includes the source file "3rdparty.cpp". Any number of sources could be listed here.
add_library (libthirdparty libthirdparty.hpp libthirdparty.cpp)

# Make sure the compiler can find include files for our "libthirdparty" library when other libraries or executables link to "libthirdparty"
target_include_directories (libthirdparty PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
