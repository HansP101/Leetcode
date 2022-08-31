class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string temp;
        stack<string> pStack;
        string ans={};
        while(getline(ss, temp, '/')){
            if (temp==".."){
                if(!pStack.empty()) pStack.pop();}
            else if (temp=="" or temp=="." or temp=="/") ; //do nothing
            else pStack.push(temp);
        }
        if(pStack.empty()) return "/";
        else{
            while(pStack.size()){
                ans="/"+pStack.top()+ans;
                pStack.pop();
            }
        }
        return ans;
    }
};
