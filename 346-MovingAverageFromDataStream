class MovingAverage {
public:
    int windowSize;
    queue<int> q;
    int subsum=0;
    MovingAverage(int size) {
        windowSize=size;
    }
    
    double next(int val) {
        q.push(val);
        if(q.size()>windowSize){
            subsum=subsum-q.front();
            q.pop();}
        subsum+=val;
        return (double)subsum/q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
