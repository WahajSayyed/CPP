 ## Task 1 Solution

// Additional DataPoint for practice

DataPoint sensor2 = {30.2, "Pressure", 1500};

DataPoint& sensor2Ref = sensor2;

// Note: Cannot reassign reference

// sensor2Ref = sensor1;  // This copies data, doesn't reassign reference

 ## Task 2 Solution
// Key safety patterns demonstrated:

// 1. Always check for nullptr before dereferencing

// 2. Set pointers to nullptr after deletion

// 3. Use proper new/delete pairing

// 4. Understand pointer arithmetic for arrays

 ## Task 3 Solution
// Key differences highlighted:

// 1. References cannot be reassigned, pointers can

// 2. References cannot be null, pointers can

// 3. References must be initialized, pointers can be declared uninitialized

// 4. Function parameters: use references for efficiency, pointers for flexibility

 ## Task 4 Solution
// Advanced safety patterns:

// 1. Input validation before allocation

// 2. Systematic null checking

// 3. RAII through destructors

// 4. Safe search and update operations

## Task 6 Solution
// Enhanced error handling for allocation failures
```try {
    int* largeArray = new int[1000000000];  // May fail on some systems
    // Use array...
    delete[] largeArray;
} catch (const bad_alloc& e) {
    cout << "Allocation failed: " << e.what() << endl;
    // Handle failure gracefully
}
```

## Task 7 Solution
// Key patterns demonstrated:

// 1. Prevent duplicate allocations with name checking

// 2. Track creation time for debugging

// 3. Automatic cleanup in destructor

// 4. Comprehensive leak detection reporting

## Task 8 Solution
/ / Advanced memory pool features:

// 1. Pre-allocation of common block sizes

// 2. Block reuse for efficiency

// 3. Memory clearing for security

// 4. Ownership tracking for debugging

// 5. Automatic pool expansion when needed


## Task 10 Solution

```// Factory function returning unique_ptr
template<typename T, typename... Args>
unique_ptr<T> createResource(Args&&... args) {
    return make_unique<T>(std::forward<Args>(args)...);
}
// Vector of unique_ptr for managing multiple servers
vector<unique_ptr<ServerConfig>> serverPool;
serverPool.push_back(createServerConfig("Server1", 8080, "Production"));
```

## Task 11 Solution
// Key shared_ptr patterns demonstrated:

// 1. Reference counting for shared resources

// 2. enable_shared_from_this for safe self-reference

// 3. weak_ptr for breaking circular dependencies

// 4. Automatic cleanup when reference count reaches zero

## Task 12 Solution
// Advanced custom deleter patterns:

// 1. Function objects with state for context-aware cleanup

// 2. Lambda expressions for simple cleanup logic

// 3. Logging and error handling in deleters

// 4. Specialized cleanup for different resource types