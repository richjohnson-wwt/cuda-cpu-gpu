Benefits of this Strategy
Testability: The core computational logic is completely decoupled from CUDA, making it easy to unit-test on any standard C++ environment.

Maintainability: You have one central place for your core algorithm (add_arrays_cpu), and the CUDA-specific code is a separate concern. If the algorithm changes, you only need to update the C++ version, and then update the kernel implementation to match.

Flexibility: You can easily switch between a CPU and GPU implementation. This is useful for debugging, as a CPU version is often easier to debug with standard tools. It also allows you to run on systems without a CUDA-capable GPU.

Incremental Development: You can start with a fully functional and tested CPU version, and then progressively migrate performance-critical sections to the GPU. This "profiling-driven" approach ensures you're only spending time optimizing the parts of the code that truly matter.

# Intial Setup - Do every time a new VM is started

    uv venv
    source .venv/bin/activate
    uv pip install conan
    conan profile detect
    Install C++ and CMake Extensions in VSCode

# Debug Config

    conan install . --output-folder=build/Debug --build=missing --settings=build_type=Debug
    cd build/Debug 
    
    # All commands in build/Debug
    cmake ../.. -G "Unix Makefiles" -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Debug
    
    cmake -B build . -DUSE_CUDA=OFF
    cmake --build .

    OR

    cmake -B build . -DUSE_CUDA=ON
    cmake --build .

    ./src/add_arrays
    ./test/tests
    ctest