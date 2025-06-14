
# 📚 Learn C++ Data Structures & Unit Testing with Google Test (WIP)

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

## 🧪 Features & Coverage

### 🔗➡️ Singly LinkedList Features Implemented:
- Insert at head, tail, or index
- Delete by value index
- Reverse list
- Detect loops
- Swap node pairs
- Convert binary linked list to decimal
- Deep copy and move support
- Edge-case aware (empty list, invalid indices, etc.)

### 🔗↔️ Doubly LinkedList Features Implemented:
- Insert at head, tail, or index
- Delete by index
- Reverse list
- etc

### 📚⬆️ Stack Features Implemented:
- push
- pop
- peek
- clear
- height


### 🧍‍♂️🧍‍♀️➡️ Queue Features Implemented:
- enQueue
- deQueue
- peek
- size
- clear


### 📌 Design Notes

> 🔄 **Why two `Node` class versions?**

This project contains **two versions** of the `Node` class. The choice impacts how nodes are accessed and manipulated. 

To keep the codebase both educational and practical:

* **SinglyLinkedList** uses a `Node` class in which some members are `private` to demonstrate proper encapsulation and accessor methods. 
This offers stricter encapsulation, which is generally good practice but can introduce more complexity in use—particularly for learners.

* **DoublyLinkedList** (and other data structures to follow) will use the simpler `Node` class that has all members as public for improved readability and faster iteration during learning.

This split allows the project to balance clean OOP principles with clarity for learners at different levels.

---

### 🧪 Unit Test Coverage
✔ test cases across typical and edge scenarios  
✔ Google Test framework integration via CMake  
✔ Optional: HTML code coverage reports via `llvm-cov` and `llvm-profdata`

---


## ✅ Memory Safety (ASan)

🧼 **Address Sanitizer Checked — No Memory Leaks Detected**

All implemented data structures and unit tests have been validated using **Address Sanitizer (ASan)** with Clang/LLVM. 
The build and test suite show **no memory leaks, use-after-free, or heap corruption** under current test coverage.

To manually run ASan checks:

```bash
cmake -B build -S . -DCODE_COVERAGE=ON -DENABLE_ASAN=ON
cmake --build build
cd build
ctest --output-on-failure
```

---

## 🚀 Getting Started

### 1. Clone the Repository

```bash
git clone https://github.com/drdenzy/cpp-data-structures-and-algorithm.git
cd cpp-data-structures-and-algorithm
````

### 2. Build & Run Tests

```bash
cmake -DCODE_COVERAGE=ON -B build -S .  
cmake --build build
cd build
ctest --output-on-failure
```

### 3. (Optional) Generate Code Coverage Report (macOS with LLVM tools)

```bash
make -C build llvm_coverage1
make -C build llvm_coverage2
open build/coverage-report-*/index.html
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

## ⭐ Support This Project

If you find this project useful or educational, please consider leaving a **⭐ star** on the repo! 
It helps others discover the project and keeps the motivation going 🙌

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

