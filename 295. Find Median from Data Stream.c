class MedianFinder {
public:
    priority_queue<int, vector<int>> smallHalfMaxHeap; //maxHeap is default.
    priority_queue<int, vector<int>, greater<int>> largeHalfMinHeap;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
       if(smallHalfMaxHeap.empty() or num<smallHalfMaxHeap.top() )
           smallHalfMaxHeap.push(num);
        else
            largeHalfMinHeap.push(num);
        //Now balancing!
        if(smallHalfMaxHeap.size()>(largeHalfMinHeap.size()+1)){
            largeHalfMinHeap.push(smallHalfMaxHeap.top());
            smallHalfMaxHeap.pop();}
        else if (largeHalfMinHeap.size()>smallHalfMaxHeap.size()+1){
             smallHalfMaxHeap.push(largeHalfMinHeap.top());
            largeHalfMinHeap.pop();}
    }
    double findMedian() {
      if(smallHalfMaxHeap.size()==largeHalfMinHeap.size()) return (double)(smallHalfMaxHeap.top()+largeHalfMinHeap.top())/2;
        else
            return (largeHalfMinHeap.size()>smallHalfMaxHeap.size())? largeHalfMinHeap.top():smallHalfMaxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
