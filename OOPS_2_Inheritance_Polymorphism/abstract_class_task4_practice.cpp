#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <map>
#include <queue>
using namespace std;

int main() {
    cout << "=== Interface-Based System Architecture ===" << endl;
    cout << "Duration: 45-60 minutes" << endl;
    cout << "Choose your scenario and implement interface-based architecture" << endl;
    
    // ========================================
    // STEP 1: Select an Architectural Scenario
    // ========================================
    cout << "\n--- Step 1: Choose Your Scenario ---" << endl;
    cout << "1. Data Persistence Layer" << endl;
    cout << "2. Communication Protocol" << endl; 
    cout << "3. Processing Pipeline" << endl;
    cout << "Select option (1-3): ";
    
    // TODO: Get user input for scenario selection
    // int choice;
    // cin >> choice;
    
    // For this starter, we'll provide templates for all three scenarios
    // Students can uncomment and work on their chosen scenario
    
    // ========================================
    // SCENARIO 1: DATA PERSISTENCE LAYER
    // ========================================
    cout << "\n=== SCENARIO 1: DATA PERSISTENCE LAYER ===" << endl;
    
    // TODO: Define IDataReader interface
    // Requirements:
    // - Pure virtual read() method
    // - Pure virtual hasNext() method  
    // - Pure virtual close() method
    // - Virtual destructor
    
    class IDataReader {
    public:
        // TODO: Virtual destructor
        // virtual ~IDataReader() = default;
        
        // TODO: Pure virtual functions
        // virtual string read() = 0;
        // virtual bool hasNext() = 0;
        // virtual void close() = 0;
        // virtual string getDataSource() const = 0;
    };
    
    // TODO: Define IDataWriter interface
    // Requirements:
    // - Pure virtual write(data) method
    // - Pure virtual flush() method
    // - Pure virtual close() method
    // - Virtual destructor
    
    class IDataWriter {
    public:
        // TODO: Virtual destructor
        
        // TODO: Pure virtual functions
        // virtual void write(const string& data) = 0;
        // virtual void flush() = 0;
        // virtual void close() = 0;
        // virtual string getDataDestination() const = 0;
    };
    
    // TODO: Implement SQLDataReader
    // Requirements:
    // - Inherit from IDataReader
    // - Implement all pure virtual functions
    // - Add SQL-specific functionality
    
    class SQLDataReader /* TODO: Add inheritance */ {
    private:
        // TODO: Add private members
        // string connectionString;
        // vector<string> resultSet;
        // size_t currentIndex;
        
    public:
        // TODO: Constructor
        // SQLDataReader(const string& connStr);
        
        // TODO: Implement IDataReader interface
        // string read() override { }
        // bool hasNext() override { }
        // void close() override { }
        // string getDataSource() const override { }
    };
    
    // TODO: Implement FileDataWriter
    // Requirements:
    // - Inherit from IDataWriter
    // - Implement all pure virtual functions
    // - Add file-specific functionality
    
    class FileDataWriter /* TODO: Add inheritance */ {
    private:
        // TODO: Add private members
        
    public:
        // TODO: Constructor and implementations
    };
    
    // TODO: Test Data Persistence Layer
    cout << "Testing Data Persistence Layer:" << endl;
    // TODO: Create objects and demonstrate polymorphic behavior
    // unique_ptr<IDataReader> reader = make_unique<SQLDataReader>(...);
    // unique_ptr<IDataWriter> writer = make_unique<FileDataWriter>(...);
    
    // ========================================
    // SCENARIO 2: COMMUNICATION PROTOCOL
    // ========================================
    cout << "\n=== SCENARIO 2: COMMUNICATION PROTOCOL ===" << endl;
    
    // TODO: Define IMessageReceiver interface
    class IMessageReceiver {
    public:
        // TODO: Virtual destructor and pure virtual functions
        // virtual ~IMessageReceiver() = default;
        // virtual string receive() = 0;
        // virtual void listen(int port) = 0;
        // virtual void stop() = 0;
        // virtual bool isListening() const = 0;
    };
    
    // TODO: Define IMessageSender interface
    class IMessageSender {
    public:
        // TODO: Virtual destructor and pure virtual functions
        // virtual ~IMessageSender() = default;
        // virtual void send(const string& message, const string& destination) = 0;
        // virtual void connect(const string& address) = 0;
        // virtual void disconnect() = 0;
        // virtual bool isConnected() const = 0;
    };
    
    // TODO: Implement TCPMessageHandler with multiple inheritance
    // Requirements:
    // - Inherit from both IMessageReceiver and IMessageSender
    // - Implement all methods from both interfaces
    // - Handle potential diamond problem (shouldn't occur here)
    
    class TCPMessageHandler /* TODO: Add multiple inheritance */ {
    private:
        // TODO: Add private members for TCP handling
        // string serverAddress;
        // int port;
        // bool connected;
        // bool listening;
        // queue<string> messageQueue;
        
    public:
        // TODO: Constructor
        // TCPMessageHandler(const string& address, int portNum);
        
        // TODO: Implement IMessageReceiver interface
        // string receive() override { }
        // void listen(int port) override { }
        // void stop() override { }
        // bool isListening() const override { }
        
        // TODO: Implement IMessageSender interface  
        // void send(const string& message, const string& destination) override { }
        // void connect(const string& address) override { }
        // void disconnect() override { }
        // bool isConnected() const override { }
    };
    
    // TODO: Implement UDPMessageSender (sender only)
    class UDPMessageSender /* TODO: Add inheritance */ {
        // TODO: Implement IMessageSender only
    };
    
    // TODO: Test Communication Protocol
    cout << "Testing Communication Protocol:" << endl;
    // TODO: Demonstrate multiple inheritance and polymorphic behavior
    
    // ========================================
    // SCENARIO 3: PROCESSING PIPELINE
    // ========================================
    cout << "\n=== SCENARIO 3: PROCESSING PIPELINE ===" << endl;
    
    // TODO: Define IProcessorStage interface
    class IProcessorStage {
    public:
        // TODO: Virtual destructor and pure virtual functions
        // virtual ~IProcessorStage() = default;
        // virtual string process(const string& input) = 0;
        // virtual bool canProcess(const string& input) const = 0;
        // virtual string getStageType() const = 0;
        // virtual int getPriority() const = 0;
    };
    
    // TODO: Define IDataConverter interface
    class IDataConverter {
    public:
        // TODO: Virtual destructor and pure virtual functions
        // virtual ~IDataConverter() = default;
        // virtual string convert(const string& input) = 0;
        // virtual string getSourceFormat() const = 0;
        // virtual string getDestinationFormat() const = 0;
        // virtual bool canConvert(const string& fromFormat, const string& toFormat) const = 0;
    };
    
    // TODO: Implement NormalizationStage
    // Requirements:
    // - Inherit from IProcessorStage
    // - Implement data normalization logic
    
    class NormalizationStage /* TODO: Add inheritance */ {
    private:
        // TODO: Add normalization-specific members
        
    public:
        // TODO: Constructor and implementations
    };
    
    // TODO: Implement EncodingConverter  
    // Requirements:
    // - Inherit from IDataConverter
    // - Handle text encoding conversions
    
    class EncodingConverter /* TODO: Add inheritance */ {
    private:
        // TODO: Add encoding-specific members
        
    public:
        // TODO: Constructor and implementations
    };
    
    // TODO: Implement ProcessingPipeline class
    // Requirements:
    // - Manage multiple IProcessorStage objects
    // - Process data through all stages
    // - Support adding/removing stages dynamically
    
    class ProcessingPipeline {
    private:
        // TODO: Container for stages
        // vector<unique_ptr<IProcessorStage>> stages;
        
    public:
        // TODO: Methods for pipeline management
        // void addStage(unique_ptr<IProcessorStage> stage);
        // void removeStage(const string& stageType);
        // string processData(const string& input);
        // void displayPipeline() const;
    };
    
    // TODO: Test Processing Pipeline
    cout << "Testing Processing Pipeline:" << endl;
    // TODO: Create pipeline and demonstrate stage processing
    
    // ========================================
    // STEP 5: Demonstrate Functionality
    // ========================================
    cout << "\n--- Step 5: Comprehensive Demo ---" << endl;
    
    // TODO: Create comprehensive demo based on chosen scenario
    // Requirements:
    // - Show polymorphic behavior
    // - Demonstrate interface flexibility
    // - Test multiple implementations
    // - Handle edge cases
    
    cout << "\nDemo Application:" << endl;
    // TODO: Implement demo that showcases your architecture
    
    // Example demo structure:
    // 1. Create instances of your implementations
    // 2. Store them in containers using interface pointers
    // 3. Process data through the system
    // 4. Show different behaviors from different implementations
    // 5. Demonstrate extensibility by adding new implementations
    
    // ========================================
    // ARCHITECTURE ANALYSIS
    // ========================================
    cout << "\n--- Architecture Analysis ---" << endl;
    
    cout << "Design Principles Applied:" << endl;
    cout << "□ Interface Segregation Principle" << endl;
    cout << "□ Open/Closed Principle" << endl;
    cout << "□ Dependency Inversion Principle" << endl;
    cout << "□ Single Responsibility Principle" << endl;
    
    cout << "\nPolymorphic Benefits Demonstrated:" << endl;
    cout << "□ Runtime behavior selection" << endl;
    cout << "□ Easy extensibility" << endl;
    cout << "□ Loose coupling between components" << endl;
    cout << "□ Testability through interface mocking" << endl;
    
    cout << "\nMultiple Inheritance Considerations:" << endl;
    cout << "□ Diamond problem avoided" << endl;
    cout << "□ Clear interface contracts" << endl;
    cout << "□ Proper virtual destructors" << endl;
    cout << "□ Unambiguous method calls" << endl;
    
    return 0;
}

/*
IMPLEMENTATION GUIDE:

STEP 1: Scenario Selection
□ Choose one of the three scenarios to focus on
□ Understand the core interfaces needed
□ Consider future extensibility requirements

STEP 2: Core Interface Design  
□ Define abstract classes with pure virtual functions
□ Keep interfaces focused and cohesive
□ Include virtual destructors for polymorphic deletion
□ Consider const-correctness for getter methods

STEP 3: Concrete Implementation
□ Implement all pure virtual functions
□ Add class-specific functionality and data members
□ Follow SOLID principles in implementation
□ Use proper error handling and validation

STEP 4: Multiple Inheritance (if applicable)
□ Carefully design inheritance hierarchy
□ Avoid diamond problem through proper design
□ Test all interface method calls
□ Ensure proper virtual destructor chains

STEP 5: Demonstration
□ Create polymorphic containers
□ Show runtime behavior selection
□ Demonstrate extensibility
□ Test error conditions and edge cases

KEY CONCEPTS TO UNDERSTAND:
- Interface segregation keeps contracts focused
- Polymorphism enables runtime flexibility
- Multiple inheritance requires careful design
- Abstract classes define contracts for implementations

COMMON PITFALLS TO AVOID:
□ Overloading interfaces with too many responsibilities
□ Forgetting virtual destructors in base classes
□ Creating diamond inheritance problems
□ Not implementing all pure virtual functions
□ Hard-coding dependencies instead of using interfaces

SUCCESS CRITERIA:
□ Clean, focused interface definitions
□ Proper implementation of all contracts
□ Successful polymorphic behavior demonstration
□ Clear separation of concerns
□ Extensible architecture that supports new implementations
□ Professional code organization and documentation
*/