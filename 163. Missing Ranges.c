class Solution {
public:
vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ans;
        
        for (int i = 0, l = lower, r; l <= upper; i++, l = r + 2) {
            r = i < nums.size() ? min(upper, nums[i] - 1) : upper;  // [l, r] is the missing range
            if (l <= r) { ans.push_back(to_string(l) + (l == r ? "" : "->" + to_string(r))); }
        }
        
        return ans;
    }
};
