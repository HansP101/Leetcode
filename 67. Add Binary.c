class Solution {
public:
    string addBinary(string a, string b) {
        while(a.size()>b.size()){b="0"+b;}
        while(b.size()>a.size()){a="0"+a;}
        int carryover=0;
        string ans;
        for(int i=a.size()-1; i>=0; i--){
            int temp=a[i]-'0'+b[i]-'0'+carryover;
            carryover=0;
            if (temp>=2){
                carryover=1;
                temp-=2;
            }
            ans=to_string(temp)+ans;   
        }
        if(carryover) return "1"+ans;
        return ans;
    }
};
