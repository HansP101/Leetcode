class Solution {
public:
    int calculate(string s) {
        stack<int> calStack;
        int curNum=0;;
        char prevOperation='+';
        for(int i=0; i<s.size(); i++){
            char curChar=s[i];
            if(isdigit(curChar)){
                curNum=curNum*10+(curChar-'0');
            }
            if((!isdigit(curChar) and !iswspace(curChar)) or i==s.size()-1){
                if(prevOperation=='+')
                    calStack.push(curNum);
                else if (prevOperation=='-')
                    calStack.push(-curNum);
                else if (prevOperation=='*'){
                    auto prevNumer=calStack.top();
                    calStack.pop();
                    calStack.push(prevNumer*curNum);
                }
                else if (prevOperation=='/'){
                    auto prevNumer=calStack.top();
                    calStack.pop();
                    calStack.push(prevNumer/curNum);
                }
                prevOperation=curChar;
                curNum=0;
            }
        }
        int ans=0;
        while(!calStack.empty()){
            ans+=calStack.top();
            calStack.pop();}
        return ans;
    }
};
