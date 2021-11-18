cmake_minimum_required(VERSION 3.10)
project(test_project)

# Set build type
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(3rdparty/fmt EXCLUDE_FROM_ALL)
add_executable(main main.cpp)
target_link_libraries(main PRIVATE fmt::fmt-header-only)
