cmake_minimum_required(VERSION 3.23)

project(CMakeList)

add_executable(helloInCPP) 

target_sources(helloInCPP
  PRIVATE
    HelloWorld.cxx
)
