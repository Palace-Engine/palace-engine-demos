cmake_minimum_required(VERSION 3.10)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "cmake")

project(palace-engine-demos)

set(CMAKE_CXX_STANDARD 20)

# ---------------------------------------------------------
# Dependencies
# ---------------------------------------------------------
add_subdirectory(dependencies/palace-engine)

add_executable(demo_01_window_spawning WIN32
    # Source files
    demos/01_window_spawning_demo/src/main.cpp
)

target_include_directories(demo_01_window_spawning PUBLIC
    dependencies/
)

target_link_libraries(demo_01_window_spawning PRIVATE
    palace-engine
    palace-definitions
    palace-compile-options)
