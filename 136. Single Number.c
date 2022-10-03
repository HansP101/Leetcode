class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> HashTable;
        for(int i=0; i<nums.size();i++){
                HashTable[nums[i]]++;
        }
         for(auto it : HashTable){
            if (it.second ==1)
                return it.first;
        }
        return 0;
    }
};
