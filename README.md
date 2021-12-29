[![Actions Status](https://github.com/meintte/MyGui/workflows/MacOS/badge.svg)](https://github.com/meintte/MyGui/actions)
[![Actions Status](https://github.com/meintte/MyGui/workflows/Windows/badge.svg)](https://github.com/meintte/MyGui/actions)
[![Actions Status](https://github.com/meintte/MyGui/workflows/Ubuntu/badge.svg)](https://github.com/meintte/MyGui/actions)
[![Actions Status](https://github.com/meintte/MyGui/workflows/Style/badge.svg)](https://github.com/meintte/MyGui/actions)
[![Codacy Badge](https://app.codacy.com/project/badge/Grade/16360d35c53c4228bc01b0b12a09afa6)](https://www.codacy.com/gh/meintte/MyGui/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=meintte/MyGui&amp;utm_campaign=Badge_Grade)
[![Language grade: C/C++](https://img.shields.io/lgtm/grade/cpp/g/meintte/MyGui.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/meintte/MyGui/context:cpp)
[![codecov](https://codecov.io/gh/meintte/MyGui/branch/master/graph/badge.svg?token=XG8BZ8JS79)](https://codecov.io/gh/meintte/MyGui)

# Mygui

Simple library to create a window and renderer to use in other projects.
Based on the starter project for c++: <https://github.com/TheLartians/ModernCppStarter> and the Hazel engine : <https://github.com/TheCherno/Hazel>. This is very much still work in progress and should at this stage not be used.

## Usage

### Build and run the standalone target

Use the following command to build and run the executable target.

```bash
cmake -S standalone -B build/standalone
cmake --build build/standalone
./build/standalone/Mygui --help
```

### Build and run test suite

Use the following commands from the project's root directory to run the test suite.

```bash
cmake -S test -B build/test
cmake --build build/test
CTEST_OUTPUT_ON_FAILURE=1 cmake --build build/test --target test

# or simply call the executable: 
./build/test/MyguiTests
```

To collect code coverage information, run CMake with the `-DENABLE_TEST_COVERAGE=1` option.

### Run clang-format

Use the following commands from the project's root directory to check and fix C++ and CMake source style.
This requires _clang-format_, _cmake-format_ and _pyyaml_ to be installed on the current system.

```bash
cmake -S test -B build/test

# view changes
cmake --build build/test --target format

# apply changes
cmake --build build/test --target fix-format
```

See [Format.cmake](https://github.com/TheLartians/Format.cmake) for details.

### Build everything at once

The project also includes an `all` directory that allows building all targets at the same time.
This is useful during development, as it exposes all subprojects to your IDE and avoids redundant builds of the library.

```bash
cmake -S all -B build
cmake --build build

# run tests
./build/test/MyguiTests
# format code
cmake --build build --target fix-format
# run standalone
./build/standalone/Mygui --help
# build docs
cmake --build build --target GenerateDocs
