# Add executable called "app" that is build from the source file "app.cpp".
add_executable (app app.cpp)

# Link the executable to the "lib library. Since the lib library has public include directories we will use those link directories when building app
target_link_libraries (app libmath libthirdparty)
