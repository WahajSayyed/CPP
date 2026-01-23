/*
 * Create a more advanced class that simulates database connection management with proper resource handling.

🔍 Practice
Complete the main function to:

Create database connections using all three constructor types

Execute some sample queries to demonstrate functionality

Use scoped blocks to trigger destructors and observe cleanup

Create copies of connections and observe the resource management
*/
#include <iostream>
#include <string>
#include <memory>
class DatabaseConnection {
private:
    std::string connectionString;
    std::string databaseName;
    bool isConnected;
    int connectionId;
    static int nextId;    
    // Simulate connection establishment
    bool establishConnection() {
        std::cout << "Establishing connection to " << databaseName << "..." << std::endl;
        // Simulate connection logic
        isConnected = true;
        return true;
    }    
    // Simulate connection cleanup
    void closeConnection() {
        if (isConnected) {
            std::cout << "Closing database connection [ID: " << connectionId << "]" << std::endl;
            isConnected = false;
        }
    }
public:
    // Default constructor
    DatabaseConnection() : connectionString("localhost:5432"), databaseName("default_db"), 
                          isConnected(false), connectionId(++nextId) {
        std::cout << "Creating default database connection [ID: " << connectionId << "]" << std::endl;
        establishConnection();
    }    
    // Parameterized constructor
    DatabaseConnection(const std::string& connStr, const std::string& dbName) 
        : connectionString(connStr), databaseName(dbName), isConnected(false), connectionId(++nextId) {
        std::cout << "Creating database connection [ID: " << connectionId << "] to " << databaseName << std::endl;
        establishConnection();
    }    
    // Copy constructor (creates new connection)
    DatabaseConnection(const DatabaseConnection& other) 
        : connectionString(other.connectionString), databaseName(other.databaseName + "_copy"), 
          isConnected(false), connectionId(++nextId) {
        std::cout << "Creating copied database connection [ID: " << connectionId 
                  << "] based on connection " << other.connectionId << std::endl;
        establishConnection();
    }    
    // Destructor
    ~DatabaseConnection() {
        std::cout << "Destroying database connection [ID: " << connectionId << "]" << std::endl;
        closeConnection();
    }    
    // Member functions
    void executeQuery(const std::string& query) {
        if (isConnected) {
            std::cout << "Executing on " << databaseName << ": " << query << std::endl;
        } else {
            std::cout << "Cannot execute - connection not established" << std::endl;
        }
    }    
    bool getConnectionStatus() const {
        return isConnected;
    }    
    int getId() const {
        return connectionId;
    }
};
// Initialize static member
int DatabaseConnection::nextId = 0;
// Complete the main function

int main() {
    std::cout << "=== Database Connection Manager ===" << std::endl;    
    // Test default constructor
    std::cout << "\n1. Creating default connection:" << std::endl;
    DatabaseConnection defaultConn;
    defaultConn.executeQuery("SELECT * FROM users");    
    // Test parameterized constructor
    std::cout << "\n2. Creating custom connections:" << std::endl;
    DatabaseConnection prodConn("prod-server:5432", "production_db");
    DatabaseConnection testConn("test-server:5432", "test_db");    
    prodConn.executeQuery("SELECT COUNT(*) FROM orders");
    testConn.executeQuery("SELECT * FROM test_table");    
    // Test copy constructor and scoping
    std::cout << "\n3. Testing connection copying:" << std::endl;
    {
        DatabaseConnection copiedConn = prodConn;  // Copy constructor
        copiedConn.executeQuery("SELECT * FROM copied_data");        
        std::cout << "Original connection ID: " << prodConn.getId() << std::endl;
        std::cout << "Copied connection ID: " << copiedConn.getId() << std::endl;        
        std::cout << "\n--- Copied connection going out of scope ---" << std::endl;
    } // copiedConn destructor called here    
    std::cout << "\n4. Original connection still works:" << std::endl;
    prodConn.executeQuery("SELECT * FROM final_query");    
    std::cout << "\n=== Program ending - cleanup phase ===" << std::endl;
    return 0;
}

/*
✅ Success Checklist
Default and parameterized constructors create connections properly

Copy constructor creates independent connections (not shared resources)

Destructors properly clean up resources when objects are destroyed

Connection IDs are assigned correctly and uniquely

💡 Key Points
Constructor Types: Default constructors provide sensible defaults, parameterized constructors allow customization, and copy constructors create independent copies

Destructor Timing: Destructors are called automatically when objects go out of scope, ensuring reliable cleanup

Resource Management: Constructors acquire resources, destructors release them, following RAII principles

Static Members: Can track class-wide information like total instance counts

❗ Common Mistakes to Avoid
Forgetting to initialize all member variables in constructors

Not making copy constructors create truly independent copies of resources

Manually calling destructors (let C++ handle this automatically)

Not handling resource acquisition failures in constructors  

🚀 Next Steps
These object lifecycle management skills are fundamental to professional C++ development. In enterprise software, you'll use these patterns to manage database connections, file handles, network resources, and memory allocation. Understanding constructor and destructor patterns enables you to build robust applications that properly acquire and release resources, preventing memory leaks and ensuring application stability in production environments.
*/
