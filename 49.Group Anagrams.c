//Group Anagrams
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anaMap;
        vector<vector<string>> ans;
        for(auto it: strs){
            string org=it;
            sort(it.begin(), it.end());
             anaMap[it].push_back(org);              
        }
        for(auto it: anaMap){
            ans.push_back(it.second);
        }
        return ans;
    }
};
