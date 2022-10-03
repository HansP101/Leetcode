class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> output;
        unordered_map<int, int> HashTable;
        for(int i=1; i<nums.size()+1;i++){
            HashTable[i]=0;
        }
        
        for(int i=0; i<nums.size(); i++){
            auto it = HashTable.find(nums[i]);
            if(it!=HashTable.end()){
                it->second+=1;
            }
        }
        
        for(auto it: HashTable){
            if(it.second==0){
                output.push_back(it.first);
            }
        }
        
      return output;  
    }
};
