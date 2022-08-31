class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> pStack;
        string ans;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(') pStack.push(i);
            else if (s[i]==')'){
                if(pStack.size()) pStack.pop();
                else s[i]='*';
            }
        }
        while(!pStack.empty()){
            auto sout=pStack.top();
            pStack.pop();
            s[sout]='*';
        }
        for(auto it: s){
            if(it!='*') ans.push_back(it);
        }
        return ans;
    }
};
