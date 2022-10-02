class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nSet;
        int res=1;
        if(nums.size()==0) return 0;
        for(auto it: nums){
            nSet.insert(it);
        }
        for(int i=0; i<nums.size(); i++){
                if(!nSet.count(nums[i]-1)){
                    int curN=nums[i];
                    int curC=0;
                    while(nSet.find(curN)!=nSet.end()){
                        curC++;
                        curN++;
                    }
                    res=max(curC, res);
                }
        }
        return res;
    }
};
