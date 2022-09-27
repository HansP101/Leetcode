class Solution {
public:
          unordered_map<char, vector<char>> pMap={{'2', {'a', 'b', 'c'}},{'3', {'d', 'e', 'f'}},{'4', {'g','h','i'}},{'5',{'j','k','l'}},{'6',{'m','n','o'}},{'7',{'p','q','r','s'}},{'8',{'t','u','v'}},{'9',{'w','x','y','z'}}};
   
        vector<string> letterCombinations(string digits) {
        if (digits.size()==0) return {};
        vector<string> ans={};
        ans.push_back("");
        for(auto it: digits){
            AddingUP(it, ans);
        }
        return ans;
    }

    void AddingUP(char c, vector<string>&ans){
        vector<string> temp;
        auto it=pMap.find(c);
        for(auto it2: it->second){
            for(auto it3: ans){
                temp.push_back(it3+it2);              
            } 
        }   
        ans=temp;
    }      
};
