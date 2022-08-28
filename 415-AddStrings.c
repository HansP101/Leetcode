class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans;
        int carry=0;
        int sizeFit=0;
        num1.size()>=num2.size() ? sizeFit=num1.size()-num2.size(): sizeFit=num2.size()-num1.size();
        if(num1.size()>=num2.size()){
            string temp=num2;
            while(sizeFit--)
                num2="0"+num2;}
        else{
            string temp=num1;
            while(sizeFit--)
                num1="0"+num1;}
    
        for(int i=num1.size()-1; i>=0; i--){
            char temp=carry+max(num1[i],num2[i])+min(num1[i], num2[i])-'0';
            if (temp>'9') {
                carry=1;
                temp=temp-10;}
            else carry=0;
            ans=temp+ans;
        }
        if (carry==1)
            ans='1'+ans;
        return ans;
    }
};
