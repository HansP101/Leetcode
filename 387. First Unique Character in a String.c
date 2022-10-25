class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> dict;
        int ans=INT_MAX;
        for(int i=0; i<s.size(); i++){
            if(dict.find(s[i])!=dict.end())
                dict[s[i]]=INT_MAX;
            else dict[s[i]]=i;
        }
        for(auto it: dict){
                ans=min(ans, it.second);
        }
        return ans==INT_MAX? -1: ans;
    }
};
