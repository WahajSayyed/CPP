# Capstone Project Instructions
### Step1: Plan your Application Structure

- Before diving into coding, sketch out the structure of your application:

- What data format will you work with? (CSV, JSON, or plain text)

- What processing functions will you implement?

- How will you organize your namespaces and functions?

- Which external library will you use?

## PRACTICE CHALLENGE 1
Create a high-level design for your data processing application. List the namespaces, key functions, and the flow of data through your application.

Example structure:

    namespaces:
    - FileIO: Functions for reading and writing files
    - DataParsing: Functions for parsing and validating data
    - DataProcessing: Functions for analyzing and transforming data
    - LibraryIntegration: Functions for using the external library
    data flow:
    1. Read data from file (FileIO)
    2. Parse data into structures (DataParsing)
    3. Process data (DataProcessing)
    4. Write results to output file (FileIO)

### Step2: Set Up External Libraries

Select an external library to use for data parsing. Here are some popular options:

- **nlohmann/json**: A modern JSON library for C++

    - GitHub: https://github.com/nlohmann/json

    - Installation: Download json.hpp and include it in your project

- **csv-parser**: Fast CSV parser for modern C++

    - GitHub: https://github.com/vincentlaucsb/csv-parser

    - Installation: Clone the repository and include the header files

- **rapidjson**: A fast JSON parser/generator for C++

    - GitHub: https://rapidjson.org

    - Installation: Download and include the header files

For this lab, you can either:

1. Download the library files and include them directly in your project

2. Use a package manager if available

3. For simplicity, you can include just the core header files needed for basic functionality

### Step 3: Implement File I/O Operations

Create functions to read data from files and write processed results. Focus on:

- Opening files safely with error checking
- Reading entire files into memory
- Writing formatted output to files
- Handling different file formats appropriately

Example file reading function:

```
#include <fstream>
#include <string>
#include <stdexcept>
#include <sstream>
std::string readFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filename);
    }    
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}
```

## PRACTICE CHALLENGE 2
Implement a function to write processed data to a file. The function should take a filename and string content as parameters, open the file for writing, and handle potential errors.

```
void writeFile(const std::string& filename, const std::string& content) {
    // Implement file writing functionality
    // 1. Open the file
    // 2. Write the content
    // 3. Handle potential errors
}
```

## Ste 4: Implement Data Parsing

Create functions to parse the raw file content into structured data that your program can process. This should include:
- Defining appropriate data structures for your specific format
- Parsing the raw file content into these structures
- Validating the data for correctness and completeness

Example data structure for CSV or JSON parsing:

```
struct DataRecord {
    std::string id;
    std::string name;
    int age;
    double value;
    std::string category;    
    // Default constructor with initialization
    DataRecord() : age(0), value(0.0) {}
};
std::vector<DataRecord> parseData(const std::string& fileContent) {
    std::vector<DataRecord> records;
    // Implementation will depend on the file format
    // ...
    return records;
}
```

### Step 5: Implement Data Processing Functions
Create at least three different functions that analyze, transform, or process the parsed data. These could include:
- Statistical calculations
- Text analysis
- Data transformations
- Filtering operations
- Aggregation by category

Example statistical function:
```
std::string calculateStatistics(const std::vector<DataRecord>& data) {
    double sum = 0.0;
    for (const auto& record : data) {
        sum += record.value;
    }
    double mean = sum / data.size();    
    std::stringstream result;
    result << "Records analyzed: " << data.size() << "\n";
    result << "Mean value: " << mean << "\n";
    // Add more statistics...    
    return result.str();
}
```

## PRACTICE CHALLENGE 3
Implement a function that filters data records based on a condition (such as age > 18 or category == "example"). The function should take a vector of records and return a new vector containing only the records that meet the condition.

```
std::vector<DataRecord> filterRecords(const std::vector<DataRecord>& records, 
                                     const std::function<bool(const DataRecord&)>& predicate) {
    // Implement filtering functionality
    // 1. Create a new vector to store filtered records
    // 2. Iterate through input records
    // 3. Add records that match the predicate to the result
    // 4. Return the filtered records
}
```

### Step 6: Use GenAI Tools for Code Generation

You can use GenAI tools like ChatGPT, GitHub Copilot, or similar services to help with:

- Generating boilerplate code
- Creating complex algorithms
- Debugging challenging problems
- Writing test cases

When using GenAI tools:

- Be clear about what you're trying to accomplish
- Review and understand the generated code
- Modify the code as needed to fit your specific requirements
- Document where and how you used AI assistance

Example GenAI prompt for a JSON parsing function:

    "Write a C++ function that parses a JSON string into a vector of DataRecord objects 
    using the nlohmann/json library. The DataRecord struct has fields for id (string), 
    name (string), age (int), value (double), and category (string)."

### Step 7: Implement Error Handling

Add robust error handling throughout your application:

- Use try-catch blocks for operations that might fail
- Provide specific error types and messages for different failure scenarios
- Implement input validation for user inputs
- Handle file I/O errors gracefully
- Validate data during parsing

Example error handling structure:

```
try {
    std::string fileContent = readFile(filename);
    auto records = parseData(fileContent);
    auto result = processData(records);
    writeFile(outputFilename, result);
} catch (const std::runtime_error& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
} catch (const std::exception& e) {
    std::cerr << "Unexpected error: " << e.what() << std::endl;
    return 1;
}
```

### Step 8: Test Your Application

Test your application with various inputs to ensure it works correctly:

- Valid data files
- Invalid or malformed data files
- Edge cases (empty files, very large files)
- Different types of processing operations

📝 **Project Deliverables**
Your completed project should include:

1. Source Code: Well-organized C++ code with proper modularization
2. External Library Integration: Documentation of the library you used and its purpose
3. Data Processing Documentation: Explanation of data formats supported and processing algorithms
4. AI Collaboration Report: Description of how GenAI tools were used and what you learned
5. User Guide: Instructions for using your application, including input formats and output interpretation

📚 **Additional Resources**

- [C++ Reference](https://en.cppreference.com/)

- [nlohmann/json Documentation](https://github.com/nlohmann/json)

- [CSV Parser Documentation](https://github.com/vincentlaucsb/csv-parser)

- [C++ File I/O Tutorial](https://www.cplusplus.com/doc/tutorial/files/)

- [Error Handling in C++](https://www.tutorialspoint.com/cplusplus/cpp_exceptions_handling.htm)

**Next Steps**: Once you’ve completed this lab, make sure to proceed to the Graded Assignment. Successfully completing and passing the graded assignment is required to earn your course completion. Take your time to review what you’ve learned in this lab before attempting it.  

🎓 **Conclusion**
This capstone project brings together many of the skills you've developed throughout the C++ Programming Fundamentals course. By creating a functional data processing application, you'll demonstrate your ability to work with complex data structures, implement file I/O operations, and apply modular programming principles. The integration of external libraries and use of GenAI tools will also prepare you for modern software development practices.

Remember to focus on writing clean, well-organized code with proper error handling and documentation. This project will not only consolidate your learning but also serve as a valuable addition to your programming portfolio.

Good luck with your implementation!