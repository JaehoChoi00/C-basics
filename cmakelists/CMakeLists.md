# CMake  

[:arrow_left: Return to Main README](../README.md)

---

## Section

> * **Prologue [`The Setup`](#prologue)**
> * **Part 1 [`Getting Started & Library`](#part-1)**
>     * [`add_library`](#the-add_library)  
>     * [`Standard Output Directories`](#standard-output-directories)
>     * [`Object Libraries`](#object-libraries)
>     * [`Interface Libraries`](#interface-libraries)  
>     * [`Imported Libraries`](#imported-libraries)
>     * [`Alias Libraries`](#alis-libraries)
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
project(CMakeList)

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
> ```-B``` = **Use relative path** to **generate** files for the build. If ***not***, then **use current directory.**  

## [Part 1:](#section)

### **Building a Library**

>
> ***cmake***
> ```cmake
> target_sources(MyLibrary
>  PRIVATE
>    library_implementation.cxx # Defines the implementation file that will be compiled into the library binary.
> 
>  # Exposes the following headers as part of the library's public interface for users to consume.
>  PUBLIC
>    FILE_SET myHeaders  # Creates a named logical group of files called 'myHeaders' that can be installed or exported together.
> 
>   # Configuration:
>    TYPE HEADERS  # Specifies that the files within this specific set are C-family header files.
>    BASE_DIRS  
>      # Sets the directory named 'include' as the search base.
>      include
>    # Lists the actual file paths belonging to this public header set.
>    FILES
>      include/library_header.h
> )
> ```
>
> Instead, simplify by removing ```TYPE```
>
> ***cmake***
> ```cmake
> target_sources(MyLibrary
>  PRIVATE
>    library_implementation.cxx
>
>  PUBLIC
>    FILE_SET HEADERS
>    BASE_DIRS
>      include
>    FILES
>      include/library_header.h
> )
> ```
>
> ---
> 
> ### ***[The ```add_library```](#section)***
>
> ### Normal Library Syntax: 
> ```cmake
> add_library(<name> [<type>] [EXCLUDE_FROM_ALL] <sources>...)
> ```  
> 
> + ```<name>``` = library targert. ***NEEDS TO BE GLOBALLY UNIQUE***  
> + ```<type>```  **[Link](https://cmake.org/cmake/help/latest/manual/cmake-buildsystem.7.html#static-libraries)**
>     + ```STATIC``` = [App + Library] -> [```./app```]  
>     + ```SHARED``` = [```./app```] -> [App] -> [Memory Address] -> [Library] 
>     + ```MODULE``` = [```./app```] -> [App Running] -> [Code Scan] ->  [Library]
>     + Default is ```STATIC```
> + ```EXCLUDE_FROM_ALL``` **[Link](https://cmake.org/cmake/help/latest/prop_tgt/EXCLUDE_FROM_ALL.html#prop_tgt:EXCLUDE_FROM_ALL)** 
>     + ```[cmake --build .]``` -> Ignore library target.
>     + ```[cmake --build . --target <name>]``` -> requested.
>     + Default is without ```EXCLUDE_FROM_ALL```
> + ```<source>``` = [Text Files] -> [Compiler] -> [Object Files] -> ```<type>```  
>
> <br>
> 
> ```FRAMEWORK``` = ***Apple Specific***
> ```cmake
> add_library(targetName SHARED example.cxx exampleC.c exampleC.h)
> set_target_properties(targetName PROPERTIES FRAMEWORK TRUE)
> ```  
>   
> ---
>
> ### ***[Standard Output Directories](#section)***
> 
> ***Syntax***:  
> ```cmake
> cmake_minimum_required(VERSION 3.23)
> project(Tutorial)  
> 
> # Send all runnable apps (Executables) to: build/bin/
> set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
> 
> # Send all Shared/Dynamic libraries to: build/lib/
> set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
> 
> # Send all Static libraries to: build/archive/
>  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/archive)
> ```  
>
> + `ARCHIVE_OUTPUT_DIRECTORY` 
>     + file path `my_project/build/archive/`
>     + Archive = `.a` -> archive of `.o`
>     + finished `.a` / `.lib` files are sent
> + `LIBRARY_OUTPUT_DIRECTORY`
>     + file path `my_project/build/lib/`  
>     + SHARED Libraries `.so` || `.dylib`
> + `RUNTIME_OUTPUT_DIRECTORY/`
>     + file path `my_project/build/bin/`
>
> ***THE POINT BEING***
>
> 1. ***WITHOUT***  
>     * OS will give up searching for the relevant file during runtime if its in a nested mess.
> 
> ```txt
> my_project/
> └── build/
>     ├── CMakeCache.txt
>     │
>     ├── app                    <-- The ./app
>     │
>     ├── audio_engine/          <-- subfolder
>     │   └── libaudio.a         <-- STATIC LIBRARY
>     │
>     └── video_engine/          <-- Deep subfolder
>         └── libvideo.so        <-- SHARED LIBRARY
> ```  
>
> 2. ***WITH***  
>     * OS only has serach in the `bin/` and `lib/` to find relevant files.
> ```txt
> my_project/
> └── build/
>     ├── CMakeCache.txt
>     │
>     ├── bin/                <-- RUNTIME directory
>     │   └── app             <-- The ./app
>     │
>     ├── lib/                <-- LIBRARY directory
>     │   └── libvideo.so     <-- SHARED LIBRARY
>     │
>     └── archive/            <-- ARCHIVE directory
>         └── libaudio.a      <-- STATIC LIBRARY
> ```  
> 
> 3. ***For the OS***
>     * `/bin` & `/lib` for `SHARED` files
> 4. ***For You***
>     * `/archive` for `STATIC` files  
>
> ---
>
> ## [Object Libraries](#section)
>
> ### Syntax: 
> ```cmake
> add_library(<name> OBJECT <sources>...)
> ```  
>
> ***What?***
>
> 1. Developer creates `.c` / `.cxx` files
> 2. Compiler generates `.o` / `.obj` binary chunks
> 3. 
>
> 
> ---
>
> ## [Interface Libraries](#section)
>
> ### Syntax: 
> ```cmake
> add_library(<name> INTERFACE SYMBOLIC)
> ``` 
>  
> ---
>
> ## [Imported Libraries](#section)
>
> ### Syntax: 
> ```cmake
> add_library(<name> <type> IMPORTED [GLOBAL])
> ``` 
> 
> ---
>
> ## [Alis Libraries](#section)
>
> ### Syntax:
> ```cmake
> add_library(<name> ALIAS <target>)  
> ```
> 



---

## [Reference:](#section)

> * Tutorial Section for [`CMake`](<https://cmake.org/cmake/help/latest/guide/tutorial/index.html>)  
> * Intuitive Tutorial on Github for [`CMake`](<https://enccs.github.io/cmake-workshop/>)
> * About [`add_library`](<https://cmake.org/cmake/help/latest/command/add_library.html#command:add_library>)
> * About [`target_sources`](<https://cmake.org/cmake/help/latest/command/target_sources.html#command:target_sources>)
