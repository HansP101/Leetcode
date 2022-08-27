struct Compare{
  bool operator()(pair<int, int>&a, pair<int, int>&b){return a.second>b.second;};//minHeap
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> ans;
    unordered_map<int, int> freqMap; //k: numsValue, v:freq.
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        
    for(auto it: nums){
      freqMap[it]++;
     }
     for(auto it: freqMap){
          pq.push(make_pair(it.first, it.second));
          if(pq.size()>k) pq.pop();
      }
     while(!pq.empty()){
       ans.push_back(pq.top().first);
       pq.pop();
     }
        return ans;
    }
};
      
