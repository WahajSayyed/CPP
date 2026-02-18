/*Extend your system to implement proper thread lifecycle management with a custom thread guard class and exception handling.

🔍 Practice
Using the code below, create a system that:
    Divides the collected data into segments for parallel risk analysis
    Uses ThreadGuard to ensure all threads complete properly
    Handles exceptions that might occur during processing
Test with both valid data and empty data segments to observe exception handling.*/
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <atomic>
#include <chrono>
#include <random>

class ThreadGuard {
private:
    std::thread& thread_;
    
public:
    explicit ThreadGuard(std::thread& t) : thread_(t) {}
    
    ~ThreadGuard() {
        if (thread_.joinable()) {
            thread_.join();
        }
    }
    
    // Prevent copying
    ThreadGuard(const ThreadGuard&) = delete;
    ThreadGuard& operator=(const ThreadGuard&) = delete;
};

void riskAnalyzer(int analyzerId, const std::vector<double>& data, 
                  double& result) {
    try {
        if (data.empty()) {
            throw std::runtime_error("No data to analyze");
        }
        
        double sum = 0.0;
        for (double value : data) {
            sum += value * value;  // Risk calculation simulation
            std::this_thread::sleep_for(std::chrono::milliseconds(5));
        }
        
        result = sum / data.size();
        std::cout << "Analyzer " << analyzerId << " calculated risk: " 
                  << result << std::endl;
                  
    } catch (const std::exception& e) {
        std::cerr << "Analyzer " << analyzerId << " error: " 
                  << e.what() << std::endl;
        result = -1.0;
    }
}
/*✅ Success Checklist
ThreadGuard automatically joins threads when going out of scope
Exception handling prevents thread crashes
All data segments are processed correctly
Resource cleanup occurs even when exceptions are thrown*/