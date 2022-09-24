class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        for(int i=0; strs[0].size(); i++){
            char temp=strs[0][i];
            for(auto it: strs){
                if(it[i]!=temp or it[i]==NULL)
                return ans;
            }
            ans+=temp;
        }
        return ans;
    }
};
