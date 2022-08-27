class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> pStack;
        int ans=0;
        for(auto it: s){
            if(it=='(') pStack.push(it);
            else if (it==')'){
                if(pStack.empty()) ans++;
                else pStack.pop();
            }
        }
        return ans+pStack.size();
    }
};
