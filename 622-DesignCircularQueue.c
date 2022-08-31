class MyCircularQueue {
public:
    vector<int> data;
    int wr, rd;
    int size;
    bool bufferfull;
    MyCircularQueue(int k) {
        data.resize(k);
        wr=0, rd=0;
        size=k;
        bufferfull=false;
    }
    
    bool enQueue(int value) {
        if(!bufferfull){
            data[wr]=value;
            wr=(wr+1)%size;
            if (wr==rd){
                 bufferfull=true;}
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        if(bufferfull) bufferfull=false;
        rd=(rd+1)%size;
        return true;
    }
    
    int Front() {
        if(isEmpty())return -1;
        return data[rd];
    }
    
    int Rear() {
        if(isEmpty())return -1;
        if(wr==0) return data[size-1];
        else return data[wr-1];
    }
    
    bool isEmpty() {
        if(wr==rd and !bufferfull)return true;
        return false;
    }
    
    bool isFull() {
        return bufferfull;
    }
};
