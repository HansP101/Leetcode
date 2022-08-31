class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i=0, j=0;
        for(i,j; i<word.size() and j<abbr.size(); ){
            if(isdigit(abbr[j])){
                if(abbr[j]=='0') return false;
                int temp=0;
                while(j<abbr.size() and isdigit(abbr[j])){
                    temp=temp*10+abbr[j]-'0';
                    j++;
                }
                i+=temp;
            }
            else{
                if(word[i]==abbr[j]) i++, j++;
                else return false;
            }
        }
        if (i==word.size() and j==abbr.size()) return true;
        return false;
    }
};
