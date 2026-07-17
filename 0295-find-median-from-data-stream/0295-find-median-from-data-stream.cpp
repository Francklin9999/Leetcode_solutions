class MedianFinder {
std::priority_queue<int, vector<int>, std::greater<int>> minHeap;
std::priority_queue<int, vector<int>, std::less<int>> maxHeap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (maxHeap.size() > 0 && maxHeap.top() > num) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        if (std::abs(static_cast<int>(maxHeap.size()) - static_cast<int>(minHeap.size())) > 1) {
            if (maxHeap.size() > minHeap.size()) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            } else {
                maxHeap.push(minHeap.top());
                minHeap.pop(); 
            }
        }


    }
    
    double findMedian() {
        if (minHeap.size() == maxHeap.size()) {
            return (static_cast<double>(minHeap.top()) + static_cast<double>(maxHeap.top())) / 2.0;
        }

        if (maxHeap.size() > minHeap.size()) return maxHeap.top();
        return minHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */