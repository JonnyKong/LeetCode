class MedianFinder {
    priority_queue<int> max_heap;   // Smaller elems
    priority_queue<int, vector<int>, greater<int>> min_heap; // Larger elems

public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        if (max_heap.size() > 0 && num < max_heap.top()) {
            max_heap.push(num);
        } else {
            min_heap.push(num);
        }
        balance();
    }

    void balance() {
        // Make the two heap sizes differ by at most 1

        // This will cause underflow ->
        // while (max_heap.size() - min_heap.size() > 1) {

        while (max_heap.size() > min_heap.size() + 1) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        while (min_heap.size() > max_heap.size() + 1) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
    
    double findMedian() {
        double ret = 0.0;
        if (max_heap.size() == 0 && min_heap.size() == 0) {
            return 0.0;
        } else if (max_heap.size() > min_heap.size()) {
            ret = max_heap.top();
        } else if (max_heap.size() < min_heap.size()) {
            ret = min_heap.top();
        } else {
            ret = ((double)(max_heap.top() + min_heap.top())) / 2;
        }
        cout << ret << endl;
        return ret;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
