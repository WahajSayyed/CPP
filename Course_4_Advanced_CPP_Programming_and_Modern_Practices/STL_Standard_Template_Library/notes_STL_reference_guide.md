# Module 1 Reference Guide

Welcome to the **Module 1 Reference Guide** — a one-stop resource for all the key concepts, syntax patterns, and techniques covered in this module on the **Standard Template Library (STL)**.

This guide is designed to reinforce your understanding and serve as a convenient reference to support you in applying these skills to real-world projects.

---

# Understanding STL Containers

STL containers are key building blocks in C++ programming, offering efficient and flexible ways to manage collections of data.

---

## Sequence Containers

### 🔹 `std::vector`

* Efficient dynamic array
* Fast random access
* Slower insertions/deletions (except at the end)
* Ideal when data is mostly appended at the back

---

### 🔹 `std::list`

* Doubly-linked list
* Efficient insertions/deletions anywhere
* No fast random access
* Best for frequently changing data accessed sequentially

---

### 🔹 `std::deque`

* Double-ended queue
* Fast insertions/removals at both ends
* Combines aspects of vectors and lists
* Suitable for flexible data manipulation

---

## Associative Containers

### 🔹 `std::set` & `std::map`

* Store elements in sorted order
* `set` → unique values
* `map` → key-value pairs
* Efficient lookup, insertion, deletion
* Ideal for ordered data retrieval

---

### 🔹 `std::unordered_set` & `std::unordered_map`

* Hash table–based
* Average O(1) lookup
* No guaranteed order
* Best for fast retrieval where order is not required

---

## Container Adaptors

### 🔹 `std::stack`

* LIFO (Last In, First Out)
* Ideal for undo operations and reverse processing

---

### 🔹 `std::queue`

* FIFO (First In, First Out)
* Useful for ordered task processing (e.g., print queues)

---

### 🔹 `std::priority_queue`

* Orders elements by priority
* Useful in job scheduling and priority-based systems

---

# Implementing STL Algorithms

STL algorithms provide powerful functions to manipulate container data.

---

## Non-Modifying Sequence Algorithms

* **`std::find`** — Locate an element
* **`std::count`** — Count occurrences
* **`std::for_each`** — Apply operation to each element

---

## Modifying Sequence Algorithms

* **`std::copy`** — Copy elements between ranges
* **`std::transform`** — Modify elements using a function
* **`std::replace`** — Replace specified values

---

## Sorting and Related Operations

* **`std::sort`** — Sort elements
* **`std::merge`** — Merge sorted ranges
* **`std::binary_search`** — Search within sorted data

---

# Utilizing Iterators and Function Objects

Iterators and function objects enhance container traversal and algorithm customization.

---

## Iterator Types

* **Input/Output Iterators** — Single-pass reading and writing
* **Forward Iterators** — Multiple forward passes
* **Bidirectional Iterators** — Forward and backward traversal
* **Random Access Iterators** — Direct element access

---

## Function Objects and Lambda Expressions

### 🔹 Function Objects (Functors)

* Objects with overloaded `operator()`
* Maintain internal state
* Reusable and flexible

---

### 🔹 Lambda Expressions

* Inline anonymous functions
* Concise and readable
* Ideal for short algorithm operations

---

# Modern C++: Introduction to C++20 Ranges

C++20 introduced **ranges**, enhancing algorithm readability and expressiveness.

---

## 🔹 Ranges

* Support lazy evaluation
* Enable pipelining of operations
* Improve maintainability

---

## 🔹 Range Adaptors

* Allow chaining transformations and filters
* Create expressive data-processing pipelines

---

# Glossary of Key Terms

* **LIFO/FIFO** — Last In, First Out / First In, First Out
* **Complexity** — Time and space efficiency of algorithms
* **Adaptors** — Objects that adapt containers for specialized behavior

---

This guide serves as your anchor while exploring STL containers, algorithms, iterators, and modern range features in C++.

Keep it handy as you strengthen your C++ programming skills and prepare for more advanced topics ahead. 🚀
