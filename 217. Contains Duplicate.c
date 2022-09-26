//O(N)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> numFreq;
        for(int i=0; i<nums.size(); i++){
         auto it=numFreq.find(nums[i]);
             if (it!=numFreq.end()) return true;
            else numFreq[nums[i]]=1;
        }
        return false;
    }
};


//nlogN
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cur = nums[0];
        for(int i=0; i<nums.size()-1;i++){
            int temp=nums[i]^nums[i+1];
            if(temp==0) return true;
        }
        return false;
    }
};
