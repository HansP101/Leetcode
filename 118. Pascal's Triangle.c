class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> temp={1};
        ans.push_back(temp);
        for(int i=0; i<numRows-1; i++){
            ans.push_back(makePaskal(ans[ans.size()-1]));
        }
        return ans;
    }
    
    vector<int> makePaskal(vector<int>& data){
        vector<int> res={};
        res.push_back(data[0]);
        for(int i=0; i<data.size()-1; i++){
            res.push_back(data[i]+data[i+1]);
        }
        res.push_back(data[data.size()-1]);
        return res;
    }
};
