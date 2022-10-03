class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    if (k == 0) return result;
    deque<int> w;
    for (int i = 0, n = (int)nums.size(); i < n; i++) {
        while (!w.empty() && w.front() <= i-k)
            w.pop_front();
        while (!w.empty() && nums[w.back()] <= nums[i])
            w.pop_back();
        w.push_back(i);
        if (i >= k-1)
            result.push_back(nums[w.front()]);
    }
    return result;
}
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
        for(int i=0; i<k; i++){
            pq.push({nums[i],i});
        }
        int temp=pq.top().first;
        ans.push_back(temp);
        for(int i=k; i<nums.size();i++){
            pq.push({nums[i],i});
            while(pq.top().second <= i-k) pq.pop();
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};
