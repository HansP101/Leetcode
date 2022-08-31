class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> subsumMap;//subsum, #of incidences
        int subsum=0;
        int ans=0;
        subsumMap[0]=1;
        for(int i=0; i<nums.size(); i++){
            subsum+=nums[i];
            
            auto it=subsumMap.find(subsum-k);
            if(it!=subsumMap.end())
            ans+=it->second;
            
            subsumMap[subsum]++;
        }
        return ans;
    }
};
