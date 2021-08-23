# Directed Weighted Graph
This project implements the directed weighted graph using C++.

## Build
---
### Dependencies
- CMake
- GoogleTest

### How to Install Dependencies
```bash
$ sudo apt install cmake libgtest-dev
```
### How to Build
```bash
$ mkdir build
$ cd build
$ cmake -G "Unix Makefiles" ..
$ make all
```

## Test
---
### How to Run Tests
```bash
# Run all tests
$ cd test
$ ctest
```
```bash
# Run all tests with detail
$ cd test
$ ctest --verbose
```
```bash
# Run all tests individually
$ cd test
$ ./NodeTest
$ ./GraphTest
$ ./WeightedGraphTest
```

## Documentation
---
Documents are generated from javadoc style written comments by using doxygen. You can find the docs at below location after build step.
```bash
build/html/index.html
```