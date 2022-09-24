class Solution {
public:
    string longestPalindrome(string s) {
        string ret;
        for(int i = 0; i < s.size(); i ++) {
            string tmp = expand(s, i, i);
            if(tmp.size() > ret.size()) ret = tmp;
            
            tmp = expand(s, i, i + 1);
            if(tmp.size() > ret.size()) ret = tmp;
        }
        return ret;
    }
    
private:
    string expand(string& s, int l, int r) {
        if(r >= s.size()) return "";
        
        while(l >= 0 && r < s.size() && s[l] == s[r]) {
            l --;
            r ++;
        }
        return s.substr(l + 1, r - l - 1);
    }
};
