
# 📚 Learn C++ Data Structures & Unit Testing with Google Test

Welcome to this hands-on C++ learning project, designed to help you build a solid understanding of Data Structures and Algorithms—while mastering how to write robust, testable C++ code using the Google Test framework.

Whether you’re a student, a self-taught developer, or preparing for technical interviews, this project offers a clear, practical pathway to strengthen your C++ fundamentals through real-world examples and unit testing best practices.

---

## ✨ What You'll Learn

✅ Data structures and Algorithm in modern C++  
✅ Writing clean, testable object-oriented C++ code  
✅ Creating unit tests with [Google Test](https://github.com/google/googletest)  
✅ Using [CMake](https://cmake.org/) to build and test C++ projects  
✅ Measuring test coverage with LLVM tools on macOS  

---

## 🧠 Project Structure

```

├── CMakeLists.txt         # Top-level build configuration
├── main.cpp               
├── src/
│   ├── node.hpp/.cpp        # Node class for singly linked list
│   └── linkedlist.hpp/.cpp  # Core LinkedList class implementation
├── tests/
│   ├── linkedlist_test.cpp  # Google Test unit tests
│   └── CMakeLists.txt       # Test target + GTest setup
├── cmake/
│   └── LLVMCodeCoverage.cmake # Optional: HTML code coverage target
└── build/                 # (ignored) CMake build directory

````

---

## 🧪 Features & Coverage

### ✅ LinkedList Features Implemented:
- Insert at head, tail, or index
- Delete by value or index
- Reverse list
- Detect loops
- Swap node pairs
- Convert binary linked list to decimal
- Deep copy and move support
- Edge-case aware (empty list, invalid indices, etc.)

### 🧪 Unit Test Coverage
✔ 25+ test cases across typical and edge scenarios  
✔ Google Test framework integration via CMake  
✔ Optional: HTML code coverage reports via `llvm-cov` and `llvm-profdata`

---

## 🚀 Getting Started

### 1. Clone the Repository

```bash
git clone https://github.com/drdenzy/cpp-data-structures-and-algorithm.git
cd cpp-data-structures-and-algorithm
````

### 2. Build & Run Tests

```bash
cmake -S . -B build -DCODE_COVERAGE=ON
cmake --build build
cd build
ctest --output-on-failure
```

### 3. (Optional) Generate Code Coverage Report (macOS with LLVM tools)

```bash
make -C build llvm_coverage
open build/coverage-report/index.html
```

---

## 🛠️ Requirements

* macOS/Linux (tested on macOS with LLVM/Clang)
* CMake ≥ 3.22
* C++20 compiler (Clang/AppleClang recommended)
* [Google Test](https://github.com/google/googletest) (automatically downloaded via CMake FetchContent)
* Optional for coverage:

    * `llvm-cov` and `llvm-profdata` (installed via `brew install llvm`)

---

## 📖 License

MIT License — free to use, modify, and share.

---

## 🙌 Acknowledgements

* [GoogleTest](https://github.com/google/googletest) for the C++ testing ecosystem
* [CMake](https://cmake.org/) for clean and flexible build configuration
* [LLVM](https://llvm.org/) for code coverage tooling on macOS

---

## ✍️ Author

I am Passionate about making C++, Go, Rust, Elixir, Python and systems programming easier to learn.
Feel free to connect on  [LinkedIn](https://www.linkedin.com/in/dr-dennis-akpenyi/).

---

