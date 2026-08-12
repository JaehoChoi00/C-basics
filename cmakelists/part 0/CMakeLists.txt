cmake_minimum_required(VERSION 4.3.1)

project(Hello_CMakeList)

add_executable(helloInCPP) 

target_sources(helloInCPP
  PRIVATE
    HelloWorld.cxx
)
