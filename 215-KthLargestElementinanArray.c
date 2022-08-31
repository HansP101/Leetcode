class Solution {
public:
    //meanheap
    
    struct Compare{
      bool operator()(int a, int b){return a>b;}  //min heap
    };
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, Compare> pq;
       // priority_queue<int, vector<int>, greater<int>> pq;
        for(int it: nums){
            pq.push(it);
            if(pq.size()>k) pq.pop();
        }
        return pq.top();
    }
};
