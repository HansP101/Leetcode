class Solution {
public:
    bool isPalindrome(string s) {
        int i=0, j=s.size()-1;
        if (j==0) return true;
        while(characterCheck(i, s)==false and i<s.size()) i++;
        while(characterCheck(j, s)==false and j>0) j--;
        if (i==j) return true;
        for(i, j; i<j; i++, j--){
            if(s[i]>='A' and s[i]<='Z') s[i]=s[i]+'a'-'A';
             if(s[j]>='A' and s[j]<='Z') s[j]=s[j]+'a'-'A';
            if(s[i]!=s[j]) return false;
            else{
                while(characterCheck(i+1, s)==false) i++;
                while(characterCheck(j-1, s)==false) j--;
            }
            
        }
        return true;
    }
    bool characterCheck(int index, string &s){
        if(s[index]>='a' and s[index]<='z')
            return true;
        if(s[index]>='A' and s[index]<='Z')
            return true;
        if(s[index]>='0' and s[index]<='9')
            return true;
        return false;
        
    }
};
/8/25 풀이
class Solution {
public:
    bool isPalindrome(string s){
	    
	    string temp;
	    for(auto c: s)
		    if(isalnum(c)) temp.push_back(filteredString(c));
        int start=0;
	    int end=temp.size()-1;
        if(temp.empty()) return true;
        for(int i=start, j=end; i<j; i++, j--){
	        if(temp[i]!=temp[j]) return false;}
        
            return true;
    }

char filteredString (char c){
    if(c>='A' and c<='Z') return c+('a'-'A');
    else return c;	
    }
};
