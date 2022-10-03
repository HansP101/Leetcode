class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> HashTable;
        int maximum=0, ans=0;
        if (nums.size()==1) 
            return nums[0];
        for(auto element: nums){
            auto it= HashTable.find(element);
            if (it != HashTable.end()){
                it->second ++;
                 if (it->second > maximum){
                maximum=it->second;
                ans=it->first;
            }
            }                
            else 
                HashTable[element]=1;
        }
        return ans;
    
    }
};
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
            return nums[nums.size()/2];   
    }
};
