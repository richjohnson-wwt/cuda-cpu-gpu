file(GLOB TEST_SOURCES *.cpp)
find_package(Catch2 REQUIRED)

add_executable(tests ${TEST_SOURCES})

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

target_include_directories(tests PRIVATE ../src)

if(USE_CUDA)
    target_sources(tests PRIVATE ../src/add_arrays_gpu.cu)
else()
    target_sources(tests PRIVATE ../src/add_arrays_cpu.cpp)
endif()
