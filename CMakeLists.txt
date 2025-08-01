cmake_minimum_required(VERSION 3.10)
project(cuda-cpu-gpu VERSION 0.1.0 LANGUAGES CXX CUDA)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(USE_CUDA "Enable CUDA support" OFF)

if(USE_CUDA)
    set(CMAKE_CUDA_ARCHITECTURES 89)
    enable_language(CUDA)
    message(STATUS "CUDA enabled")
    set(SOURCES
        src/main.cpp
        src/add_arrays.h
        src/add_arrays_gpu.cu
    )
else()
    message(STATUS "CUDA disabled — using CPU")
    set(SOURCES
        src/main.cpp
        src/add_arrays.h
        src/add_arrays_cpu.cpp
    )
endif()

add_executable(add_arrays ${SOURCES})
target_include_directories(add_arrays PRIVATE src)

# Unit tests
add_subdirectory(test)