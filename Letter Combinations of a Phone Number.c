class Solution {
public:
          unordered_map<char, vector<char>> pMap={{'2', {'a', 'b', 'c'}},{'3', {'d', 'e', 'f'}},{'4', {'g','h','i'}},{'5',{'j','k','l'}},{'6',{'m','n','o'}},{'7',{'p','q','r','s'}},{'8',{'t','u','v'}},{'9',{'w','x','y','z'}}};
    
    vector<string> letterCombinations(string digits) {
  
        if (digits.size()==0) return {};
        auto it=pMap.find(digits[0]);
        vector<string> ans;
        ans.resize(it->second.size());
        int i=0;
        for(auto it2: it->second)
            ans[i++].push_back(it2);
        
        digits=digits.substr(1);
        for(auto it: digits){
            BackTracking(it, ans);
        }
        return ans;
    }
    
    void BackTracking(char c, vector<string>&ans){
        vector<string> temp;
    //    vector<string> temp2;
        auto it=pMap.find(c);
        for(auto it2: it->second){
            for(int i=0; i<ans.size();i++){
                temp.push_back(ans[i]+it2);              
            } 
        }   
        ans=temp;
    }
        
        
};
