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