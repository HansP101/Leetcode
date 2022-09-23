class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> map;
        int left = 0;
        int maxLen = 0;
        for(int i=0;i<s.size();i++){
            if(map.find(s[i])==map.end())
                map[s[i]] = i;
            else{
                left = max(left,map[s[i]] + 1); //can't go back
                map[s[i]] = i;
            }               
            maxLen = max(maxLen,i-left+1);
        }
        return maxLen;
    }
};
