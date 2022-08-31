class Solution {
public:
    bool isNumber(string s) {
        bool eSeen=false, dotSeen=false, numberSeen=false;
        int signSeen=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]>='0' and s[i]<='9') numberSeen=true;
            else if(s[i]=='+' or s[i]=='-'){
                signSeen++;
                if(signSeen>2 or (i>0 and s[i-1]!='e' and s[i-1]!='E') or i==s.size()-1) return false;
            }
            else if (s[i]=='.'){
                if(dotSeen==true or eSeen==true or (i==s.size()-1 and numberSeen==false)) return false;
                dotSeen=true;
            }
            else if (s[i]=='e' or s[i]=='E'){
                if(eSeen==true or numberSeen==false or i==s.size()-1) return false;
                eSeen=true;
            }else
                return false;
        }
        return true;
    }
};
