class Solution {
public:
   
    vector<int> twoSum(vector<int>& nums, int target) {
         unordered_map<int, int> numMap; //value, index
        numMap[nums[0]]=0;
        for(int i=1; i<nums.size();i++){
            auto it=numMap.find(target-nums[i]);
                if(it !=numMap.end())
                    return {it->second, i};
                else
                    numMap[nums[i]]=i;
        }
        return {0,0};
    }
};
