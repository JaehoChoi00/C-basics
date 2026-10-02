cmake_minimum_required(VERSION 3.20)

project(CMakeExample
    VERSION 1.0.0
    LANGUAGES C
)

# C Standard

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Expresso Package

add_library(Expresso::expresso STATIC IMPORTED)

set_target_properties(Expresso::expresso PROPERTIES
    IMPORTED_LOCATION
        "${CMAKE_CURRENT_SOURCE_DIR}/external/expresso/lib/libexpresso.a"

    INTERFACE_INCLUDE_DIRECTORIES
        "${CMAKE_CURRENT_SOURCE_DIR}/external/expresso/include"
)

# Library

add_library(CMakeExample STATIC
    src/projectfile1.c
    src/projectfile2.c
    src/projectfile3.c
)

target_include_directories(CMakeExample
    PUBLIC
        include
)

target_link_libraries(CMakeExample
    PUBLIC
        Expresso::expresso
)

# Executable

add_executable(CMakeExampleProgram
    src/main.c
)

target_link_libraries(CMakeExampleProgram
    PRIVATE
        CMakeExample
)

# Testing

enable_testing()

add_executable(TestOne test/test1.c)
target_link_libraries(TestOne PRIVATE CMakeExample Expresso::expresso)

add_executable(TestTwo test/test2.c)
target_link_libraries(TestTwo PRIVATE CMakeExample Expresso::expresso)

add_executable(ExpressoTest test/test_expresso.c)
target_link_libraries(ExpressoTest PRIVATE CMakeExample Expresso::expresso)

add_test(NAME TestOne COMMAND TestOne)
add_test(NAME TestTwo COMMAND TestTwo)
add_test(NAME ExpressoTest COMMAND ExpressoTest)