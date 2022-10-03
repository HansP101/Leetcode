class Solution {
public:
    int countBinarySubstrings(string s) {
        int sav_conseq=1;
        int conseq=1;
        int ans=0;

        for (int i=1; i<s.size(); i++){
            if(s[i-1] != s[i]){
                ans+=min(sav_conseq, conseq); 
                sav_conseq=conseq;
                conseq=1;
            }else{
                conseq+=1;
                }
            }
                return ans+=min(sav_conseq, conseq)-1; 
          }
};
