class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int leftToRemove=0;
        int rightToRemove=0;
        unordered_set<string> ansSet;
        for(auto c: s){
            if(c=='(') leftToRemove++;
            else if (c==')'){
                if(leftToRemove>0) leftToRemove--;
                else rightToRemove++;
            }
        }
        DFShelper(s, 0, leftToRemove, rightToRemove, 0, {} ,ansSet);
        return vector<string>(ansSet.begin(), ansSet.end());
    }
    void DFShelper(string s, int index, int leftToRemove, int rightToRemove, int numPair, string candidate, unordered_set<string>&ansSet){
        if((leftToRemove+rightToRemove)>(s.length()-index)) return;
        if(index==s.length()){
            if(leftToRemove==0 and rightToRemove==0 and numPair==0) ansSet.insert(candidate);
            return;
        }
        if(s[index]!='(' and s[index]!=')') DFShelper(s, index+1, leftToRemove, rightToRemove, numPair, candidate+s[index], ansSet);
        else{
            if(s[index]=='('){
                if(leftToRemove>0) DFShelper(s, index+1, leftToRemove-1, rightToRemove, numPair, candidate,ansSet);
                DFShelper(s, index+1, leftToRemove, rightToRemove, numPair+1, candidate+s[index], ansSet);
            }else if (s[index]==')'){
                if(rightToRemove>0) DFShelper(s, index+1, leftToRemove, rightToRemove-1, numPair, candidate, ansSet);
                if(numPair>0){
                    DFShelper(s, index+1, leftToRemove, rightToRemove, numPair-1, candidate+s[index], ansSet);
                }
            }
        }
    }
};
