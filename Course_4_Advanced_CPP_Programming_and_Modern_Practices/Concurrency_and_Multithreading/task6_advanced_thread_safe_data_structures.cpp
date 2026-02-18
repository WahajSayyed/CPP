/*You're developing a high-frequency trading system that requires thread-safe data structures capable of handling thousands of concurrent operations per second while maintaining data integrity.

🔍 Practice
Using the code below, implement a benchmarking system that tests the thread-safe map with multiple reader and writer threads. Consider:
How std::shared_mutex allows concurrent read access while ensuring exclusive write access
The performance difference between shared locks (readers) and unique locks (writers)
Create a test scenario with 10 reader threads and 3 writer threads accessing the same map concurrently. Measure the performance impact of different synchronization strategies.*/

#include <iostream>
#include <mutex>
#include <shared_mutex>
#include <vector>
#include <thread>
#include <chrono>
#include <random>
#include <map>

template<typename T>
class ThreadSafeMap {
private:
    mutable std::shared_mutex mutex_;
    std::map<std::string, T> data_;
    
public:
    void insert(const std::string& key, const T& value) {
        std::unique_lock<std::shared_mutex> lock(mutex_);
        data_[key] = value;
    }
    
    bool find(const std::string& key, T& value) const {
        std::shared_lock<std::shared_mutex> lock(mutex_);
        auto it = data_.find(key);
        if (it != data_.end()) {
            value = it->second;
            return true;
        }
        return false;
    }
    
    size_t size() const {
        std::shared_lock<std::shared_mutex> lock(mutex_);
        return data_.size();
    }
    
    std::vector<std::pair<std::string, T>> getAllEntries() const {
        std::shared_lock<std::shared_mutex> lock(mutex_);
        return std::vector<std::pair<std::string, T>>(data_.begin(), data_.end());
    }
};

// Performance monitoring class
class PerformanceTracker {
private:
    mutable std::mutex mutex_;
    std::chrono::high_resolution_clock::time_point startTime_;
    std::vector<double> operationTimes_;
    
public:
    PerformanceTracker() : startTime_(std::chrono::high_resolution_clock::now()) {}
    
    void recordOperation(double duration) {
        std::lock_guard<std::mutex> lock(mutex_);
        operationTimes_.push_back(duration);
    }
    
    void printStatistics() const {
        std::lock_guard<std::mutex> lock(mutex_);
        if (operationTimes_.empty()) return;
        
        double sum = 0.0;
        for (double time : operationTimes_) {
            sum += time;
        }
        double average = sum / operationTimes_.size();
        
        std::cout << "Operations completed: " << operationTimes_.size() << std::endl;
        std::cout << "Average operation time: " << average << " ms" << std::endl;
    }
};

int main() {
    ThreadSafeMap<double> priceMap;
    PerformanceTracker tracker;
    
    // Writer threads
    std::vector<std::thread> writers;
    for (int i = 0; i < 3; ++i) {
        writers.emplace_back([&, i]() {
            for (int j = 0; j < 100; ++j) {
                auto start = std::chrono::high_resolution_clock::now();
                
                std::string key = "stock" + std::to_string(i * 100 + j);
                double price = 100.0 + (rand() % 10000) / 100.0;
                priceMap.insert(key, price);
                
                auto end = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration<double, std::milli>(end - start).count();
                tracker.recordOperation(duration);
            }
        });
    }
    
    // Reader threads
    std::vector<std::thread> readers;
    for (int i = 0; i < 10; ++i) {
        readers.emplace_back([&, i]() {
            for (int j = 0; j < 50; ++j) {
                auto start = std::chrono::high_resolution_clock::now();
                
                std::string key = "stock" + std::to_string(rand() % 300);
                double price;
                bool found = priceMap.find(key, price);
                
                auto end = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration<double, std::milli>(end - start).count();
                tracker.recordOperation(duration);
                
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
            }
        });
    }
    
    for (auto& t : writers) t.join();
    for (auto& t : readers) t.join();
    
    tracker.printStatistics();
    std::cout << "Final map size: " << priceMap.size() << std::endl;
    
    return 0;
}

/*✅ Success Checklist
Multiple readers can access the map simultaneously without blocking each other
Writers get exclusive access and block all other operations
No data corruption occurs during concurrent read/write operations
Performance metrics show the benefits of reader-writer synchronization*/