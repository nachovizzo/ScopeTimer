cmake_minimum_required(VERSION 3.10)
project(test_project)

# Set build type
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

include(3rdparty/fmt.cmake)
add_executable(main main.cpp)
target_link_libraries(main PRIVATE fmt)
target_include_directories(main PRIVATE ${CMAKE_SOURCE_DIR}/include)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/
        DESTINATION ${CMAKE_INSTALL_PREFIX}/include/)
