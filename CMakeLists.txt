cmake_minimum_required(VERSION 3.10)
project(prism)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src/ext/glm)

add_executable(prism
        src/prism/main.cpp
        src/prism/film.cpp

)

target_link_libraries(prism PRIVATE glm::glm)
target_include_directories(prism PRIVATE src)
