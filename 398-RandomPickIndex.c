class Solution {
public:
    unordered_map<int, vector<int>> myMap;
    Solution(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            myMap[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        auto it=myMap.find(target);
        return it->second[rand()%(it->second.size())];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
