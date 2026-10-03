# CMake

[:arrow_left: Return to Main README](../README.md)

---

## Sections

> * [`Layer 1: Minimal Executable`](#layer-1-minimal-executable)
> * [`Layer 2: Adding a Static Library & Dependencies`](#layer-2-adding-a-static-library--dependencies)
> * [`Layer 3: Adding Testing Infrastructure`](#layer-3-adding-testing-infrastructure)
> * [`Layer 4: Full Production Configuration (Original)`](#layer-4-full-production-configuration-original)
> * [`Standard Project Structure`](#standard-project-structure)
> * [`File Relationship`](#file-relationship)
> * [`Build Process`](#build-process)
> * [`References`](#references)

---

### Layer 1: Minimal Executable

Building the intuition for minimal cmake.

```cmake
cmake_minimum_required(VERSION [cmake_version])

project([project_name]
    VERSION [major.minor.patch]
    LANGUAGES C
)

# C Standard

set(CMAKE_C_STANDARD [c_standard])
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Executable

add_executable([executable_name]
    src/main.c
)
```

---

### Layer 2: Adding a Static Library & Dependencies

```cmake
cmake_minimum_required(VERSION [cmake_version])

project([project_name]
    VERSION [major.minor.patch]
    LANGUAGES C
)

# C Standard

set(CMAKE_C_STANDARD [c_standard])
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# LAYER 2 ADDITIONS: Dependencies & Library Target

# Dependencies

find_package([package_name] REQUIRED)

# Library

add_library([library_name] STATIC
    src/[projectfile1.c]
    src/[projectfile2.c]
    src/[projectfile3.c]
)

target_include_directories([library_name]
    PUBLIC
        include
)

target_link_libraries([library_name]
    PUBLIC
        [dependency_name]
)

# Executable

add_executable([executable_name]
    src/main.c
)

# LAYER 2 ADDITIONS: Executable Linkage

target_link_libraries([executable_name]
    PRIVATE
        [library_name]
)
```

---

### Layer 3: Adding Testing Infrastructure

```cmake
cmake_minimum_required(VERSION [cmake_version])

project([project_name]
    VERSION [major.minor.patch]
    LANGUAGES C
)

# C Standard

set(CMAKE_C_STANDARD [c_standard])
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Dependencies

find_package([package_name] REQUIRED)

# Library

add_library([library_name] STATIC
    src/[projectfile1.c]
    src/[projectfile2.c]
    src/[projectfile3.c]
)

target_include_directories([library_name]
    PUBLIC
        include
)

target_link_libraries([library_name]
    PUBLIC
        [dependency_name]
)


# Executable

add_executable([executable_name]
    src/main.c
)

target_link_libraries([executable_name]
    PRIVATE
        [library_name]
)


# ---------------------------------------------------------
# LAYER 3 ADDITIONS: CTest Target Registrations
# ---------------------------------------------------------

# Testing

enable_testing()

add_executable([test_name1]
    test/[test1.c]
)

target_link_libraries([test_name1]
    PRIVATE
        [library_name]
)

add_test(
    NAME [test_name1]
    COMMAND [test_name1]
)


add_executable([test_name2]
    test/[test2.c]
)

target_link_libraries([test_name2]
    PRIVATE
        [library_name]
)

add_test(
    NAME [test_name2]
    COMMAND [test_name2]
)


add_executable([test_name3]
    test/[test3.c]
)

target_link_libraries([test_name3]
    PRIVATE
        [library_name]
)

add_test(
    NAME [test_name3]
    COMMAND [test_name3]
)
```

---

### Layer 4: Full Production Configuration (Original)

The complete configuration setup, incorporating system install location defaults, target exports, and downstream configuration package generation.

```cmake
cmake_minimum_required(VERSION [cmake_version])

project([project_name]
    VERSION [major.minor.patch]
    LANGUAGES C
)

# C Standard

set(CMAKE_C_STANDARD [c_standard])
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)


# CMake Modules

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)


# Dependencies

find_package([package_name] REQUIRED)


# Library

add_library([library_name] STATIC
    src/[projectfile1.c]
    src/[projectfile2.c]
    src/[projectfile3.c]
)

target_include_directories([library_name]
    PUBLIC
        include
)

target_link_libraries([library_name]
    PUBLIC
        [dependency_name]
)


# Executable

add_executable([executable_name]
    src/main.c
)

target_link_libraries([executable_name]
    PRIVATE
        [library_name]
)


# Testing

enable_testing()

add_executable([test_name1]
    test/[test1.c]
)

target_link_libraries([test_name1]
    PRIVATE
        [library_name]
)

add_test(
    NAME [test_name1]
    COMMAND [test_name1]
)


add_executable([test_name2]
    test/[test2.c]
)

target_link_libraries([test_name2]
    PRIVATE
        [library_name]
)

add_test(
    NAME [test_name2]
    COMMAND [test_name2]
)


add_executable([test_name3]
    test/[test3.c]
)

target_link_libraries([test_name3]
    PRIVATE
        [library_name]
)

add_test(
    NAME [test_name3]
    COMMAND [test_name3]
)


# Installation

install(
    TARGETS [library_name]
    EXPORT [project_name]Targets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(
    DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)


# Export

install(
    EXPORT [project_name]Targets
    FILE [project_name]Targets.cmake
    NAMESPACE [project_name]::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/[project_name]
)


# Package Configuration

configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/[project_name]Config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/[project_name]Config.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/[project_name]
)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/[project_name]ConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

install(
    FILES
        ${CMAKE_CURRENT_BINARY_DIR}/[project_name]Config.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/[project_name]ConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/[project_name]
)
```

---

### [Standard Project Structure](#sections)

```text
[project_name]/
│
├── CMakeLists.txt
│
├── include/
│   ├── [projectfile1.h]
│   ├── [projectfile2.h]
│   └── [projectfile3.h]
│
├── src/
│   ├── [projectfile1.c]
│   ├── [projectfile2.c]
│   ├── [projectfile3.c]
│   └── main.c
│
├── test/
│   ├── [test1.c]
│   ├── [test2.c]
│   └── [test3.c]
│
├── cmake/
│   └── [project_name]Config.cmake.in
│
└── build/
```

`build/` is generated by CMake and normally should not be written manually.

---

### [File Relationship](#sections)

```text
[projectfile1.h]
        │
        │ #include
        ▼
[projectfile1.c]
        │
        │ Compiler
        ▼
[projectfile1.o]


[projectfile2.h]
        │
        │ #include
        ▼
[projectfile2.c]
        │
        │ Compiler
        ▼
[projectfile2.o]


[projectfile3.h]
        │
        │ #include
        ▼
[projectfile3.c]
        │
        │ Compiler
        ▼
[projectfile3.o]


[projectfile1.o] ─┐
[projectfile2.o] ─┼→ [library_name]
[projectfile3.o] ─┘         │
                            │
                            ▼
                     [executable_name]

[test1.c] ─→ [test_name1]

[test2.c] ─→ [test_name2]

[test3.c] ─→ [test_name3]

[test_name1] ─┐
[test_name2] ─┼→ CTest
[test_name3] ─┘
```

---

### [Build Process](#sections)

```text
CMakeLists.txt
      │
      ▼
    CMake
      │
      ├── Configure
      │
      ├── Generate Build System
      │
      ▼
   Compiler
      │
      ├── [projectfile1.c] → [projectfile1.o]
      ├── [projectfile2.c] → [projectfile2.o]
      └── [projectfile3.c] → [projectfile3.o]
                         │
                         ▼
                      Linker
                         │
                         ▼
                  [library_name]
                         │
                         ▼
                  [executable_name]

[test1.c] ──→ [test_name1] ──┐
                             │
[test2.c] ──→ [test_name2] ──┼→ CTest
                             │
[test3.c] ──→ [test_name3] ──┘
```

***`Configure`***

```bash
cmake -S . -B build
```

***`Build`***

```bash
cmake --build build
```

***`Run Application`***

```bash
./build/[executable_name]
```

***`Run Individual Tests`***

```bash
./build/[test_name1]
./build/[test_name2]
./build/[test_name3]
```

***`Run Test Suite`***

```bash
ctest --test-dir build
```

***`Run Test Suite With Output`***

```bash
ctest --test-dir build --output-on-failure
```

---

### [References](#sections)

> * [CMake Tutorial](https://cmake.org)
> * [CMake Documentation](https://cmake.org/cmake/help/latest/)
> * [ENCCS CMake Workshop](https://enccs.github.io/cmake-workshop/)

[:arrow_up: Return to Top](#cmake)
