class Solution {
public:
    bool validPalindrome(string s) {
       return palindromeCheckByIndex(s,0,s.size()-1, 0);
    }
    bool palindromeCheckByIndex(string s, int start, int end, int count){
        if(count>1) return false;
        while(start<end){
            if(s[start]==s[end]){
                start++,end--;
            }
            else
                 return palindromeCheckByIndex(s, start+1, end, count+1)|| palindromeCheckByIndex(s, start, end-1, count+1);
        }
        return true;
    }
};
