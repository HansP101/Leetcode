class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool decreasing=false;
        bool increasing=false;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]<nums[i+1]) increasing=true;
            if(nums[i]>nums[i+1]) decreasing=true;
            if(increasing and decreasing ) return false;
        }
        return true;
    }
};
