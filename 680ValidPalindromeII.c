class Solution {
public:
    bool block=false;
    bool validPalindrome(string s) {
       return palindromecheck(s, 0, s.size()-1, block); 
    }
    
    bool palindromecheck(string s, int i, int j, bool block){
        while(s[i]==s[j] and i<j){
            i++;
            j--;
        }
        if(i==j or (i-j==1 and s[j]==s[i])) return true;
            if(!block){
                 block=true;
                return palindromecheck(s, i+1, j, block)|| palindromecheck(s, i, j-1, block);}
        
            return false;
        
    }
};


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
