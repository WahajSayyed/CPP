/*Implement a producer-consumer pattern using condition variables to coordinate between data collection and processing threads.

🔍 Practice
Using the code below, build a complete producer-consumer system where:
Producer threads generate data and add it to the thread-safe queue
Consumer threads process data from the queue as it becomes available
The system gracefully shuts down when all data is processed
Experiment with different numbers of producers and consumers to observe performance characteristics.*/

#include <condition_variable>
#include <queue>

class ThreadSafeQueue {
private:
    mutable std::mutex mutex_;
    std::queue<double> queue_;
    std::condition_variable condition_;
    bool finished_ = false;
    
public:
    void push(double item) {
        std::lock_guard<std::mutex> lock(mutex_);
        queue_.push(item);
        condition_.notify_one();
    }
    
    bool pop(double& item) {
        std::unique_lock<std::mutex> lock(mutex_);
        condition_.wait(lock, [this] { return !queue_.empty() || finished_; });
        
        if (queue_.empty()) {
            return false;  // No more items and producer finished
        }
        
        item = queue_.front();
        queue_.pop();
        return true;
    }
    
    void finish() {
        std::lock_guard<std::mutex> lock(mutex_);
        finished_ = true;
        condition_.notify_all();
    }
    
    size_t size() const {
        std::lock_guard<std::mutex> lock(mutex_);
        return queue_.size();
    }
};
/*✅ Success Checklist
Producer threads successfully add data to the queue
Consumer threads wait appropriately when queue is empty
All produced data gets consumed without loss
System shuts down cleanly when production is complete*/