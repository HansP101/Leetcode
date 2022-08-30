class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.push_back({});
        for(auto num: nums){
            vector<vector<int>> temp=ans;
            for(int i=0; i<ans.size(); i++){
               temp[i].push_back(num);
            }
            for(auto it: temp)
            ans.push_back(it);      
        }
        return ans;
    }
};
