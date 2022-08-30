class Solution {
public:
    struct Compare{
            bool operator()(const pair<int, int> &a, const pair<int, int>&b){
          return a.first==b.first? a.second> b.second: a.first>b.first; //minHeap
      }  
    };
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> minHeap;
        for(int i=0; i<arr.size(); i++){
            minHeap.push(make_pair(abs(arr[i]-x), i));}
        for(int i=0; i<k; i++){
            auto it=minHeap.top();
            ans.push_back(arr[it.second]);
            minHeap.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
