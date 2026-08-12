# CMake  

[:arrow_left: Return to Main README](../README.md)

---

## Section

> * **Prologue [`The start`](#prologue)**
> * [`References`](#reference)

---

## [Prologue:](#section)

***bash***

```bash
    cmake --version
```

***cmake***

```cmake
cmake_minimum_required(VERSION 3.23)

# Defines the name of the project.
project(Hello_CMakeList)

# Declares a new executable target named 'helloInCPP'.
add_executable(helloInCPP) 

# Attaches source files to the 'helloInCPP' executable target.
target_sources(helloInCPP
PRIVATE
    # PRIVATE means these source files are only used to build this target
    HelloWorld.cxx
)
```

***bash***

```bash
    cmake -B build
    cmake --build build
    ./build/helloInCPP # or ./build/helloInCPP.exe
```



---

## [Reference:](#section)

> * Tutorial Section for [`CMake`](<https://cmake.org/cmake/help/latest/guide/tutorial/index.html>)  
> * Intuitive Tutorial on Github for [`CMake`](<https://enccs.github.io/cmake-workshop/>)
