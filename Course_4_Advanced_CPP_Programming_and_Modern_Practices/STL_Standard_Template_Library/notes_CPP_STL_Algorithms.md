# STL Algorithm Categories and Modern Range Processing

---

## Introduction to STL Algorithm Categories

In C++, algorithms are not just a collection of operations—they're powerful tools that determine how efficiently our programs run. The **Standard Template Library (STL)** provides a rich suite of algorithms designed to optimize data manipulation while maintaining reliability and performance.

As you advance in C++ programming, mastering these algorithms will enhance your code’s:

* Efficiency
* Elegance
* Maintainability

---

# Exploring Non-Modifying Sequence Algorithms

## Understanding Non-Modifying Algorithms

Non-modifying sequence algorithms allow you to process or examine data **without altering its structure or content**. These are essential when data integrity must remain intact.

---

### 🔹 `std::find`

Scans a container to locate the first instance of a specified element.

```cpp
std::vector<int> numbers = {1, 2, 3, 4, 5};

auto it = std::find(numbers.begin(), numbers.end(), 3);  // Finds the value 3
```

---

### 🔹 `std::count`

Determines how many times a specific element appears.

```cpp
int count = std::count(numbers.begin(), numbers.end(), 5);  // Counts occurrences of 5
```

---

### 🔹 `std::for_each`

Applies a function to every element in a range.

```cpp
std::for_each(numbers.begin(), numbers.end(),
              [](int n){ std::cout << n << " "; });  // Prints each number
```

---

# Delving into Modifying Sequence Algorithms

When you need to alter a dataset, modifying algorithms come into play.

---

### 🔹 `std::copy`

Copies elements from one range to another.

```cpp
std::vector<int> copy_numbers(numbers.size());

std::copy(numbers.begin(), numbers.end(), copy_numbers.begin());
```

---

### 🔹 `std::transform`

Applies a transformation to each element.

```cpp
std::transform(numbers.begin(), numbers.end(),
               numbers.begin(),
               [](int n){ return n * 2; });  // Doubles each number
```

---

### 🔹 `std::replace`

Replaces all occurrences of a value with another.

```cpp
std::replace(numbers.begin(), numbers.end(), 3, 99);
```

---

# Sorting and Related Algorithms

Sorting enables efficient organization and retrieval of data.

---

### 🔹 `std::sort`

Sorts elements in ascending order (by default).

```cpp
std::sort(numbers.begin(), numbers.end());
```

---

### 🔹 `std::merge`

Merges two sorted ranges into one sorted range.

```cpp
std::vector<int> v1 = {1, 3, 5};
std::vector<int> v2 = {2, 4, 6};
std::vector<int> result(v1.size() + v2.size());

std::merge(v1.begin(), v1.end(),
           v2.begin(), v2.end(),
           result.begin());
```

---

### 🔹 `std::binary_search`

Checks for the presence of a value in a sorted range.

```cpp
bool found = std::binary_search(numbers.begin(), numbers.end(), 3);
```

---

# Modern Range Processing in C++20

C++20 introduced **range-based algorithms**, making code more expressive and concise.

---

## Advantages of Range-Based Algorithms

* **Simplicity:** Reduces boilerplate code
* **Readability:** More intuitive, almost like natural language
* **Composability:** Supports chaining operations

---

## Range Adaptor Pipeline Example

```cpp
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    auto results = numbers
        | std::views::transform([](int n) { return n * n; })
        | std::views::filter([](int n) { return n % 2 != 0; });

    for (int num : results) {
        std::cout << num << " ";
    }

    return 0;
}
```

### What Happens Here?

* `transform` squares each number
* `filter` keeps only odd values
* The pipeline chains operations cleanly and efficiently

---

# Performance Implications

While ranges improve readability and composability, their performance still depends on the underlying algorithms.

Understanding algorithmic complexity remains essential to writing efficient C++ applications.

---

# Conclusion

Mastering C++ STL algorithms—from classic iterator-based approaches to modern C++20 ranges—empowers you to manage data effectively.

These tools help you build applications that are:

* Performant
* Readable
* Scalable

Continue practicing these algorithms to develop the expertise needed for high-performance, modern C++ development.
