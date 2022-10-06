class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string current;
        DPbackTrackingHelper(n, 0, 0, current, ans);
        return ans;
    }
    void DPbackTrackingHelper(int n, int l, int r, string current, vector<string>&ans){
        if(l==n and r==n) ans.push_back(current);
        else{
            if(l<n) DPbackTrackingHelper(n, l+1, r, current+'(', ans); //first let's increase l to all the way and backtracking will kick in
            if(r<l) DPbackTrackingHelper(n, l, r+1, current+')', ans);
        }
    }
};
