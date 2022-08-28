/*
23->5
23+2->1
23+2+4->5


23=6x3+5
23+2=6x4+1
23+2+4=6x4+5

23+2+4 - 23= (6x4+5) - (6x3+5)= 6x(4-3) meaning "2+4" is 6 multiple.

*/

class Solution{
public:
    bool checkSubarraySum(vector<int>& nums, int k){
        unordered_map<int, int> myMap;
        int subSum=0;
        myMap[0]=-1; //for the case of subSum itself is k multiple.
        for(int i=0;i<nums.size(); i++){
            subSum+=nums[i];
            auto it=myMap.find(subSum%k);
            if(it!=myMap.end()) {
                if (i- it->second>1)return true;}
            else myMap[subSum%k]=i;
        }
        return false;
    }
};
