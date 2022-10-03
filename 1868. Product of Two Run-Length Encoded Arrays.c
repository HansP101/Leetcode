class Solution {
public:
    vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) {
       int e1=encoded1.size();
        int e2=encoded2.size();
        vector<vector<int>> ans;
        int d1=0, d2=0;
        for (int i=0,j=0; i<e1 and j<e2; ){
            int index=min(encoded1[i][1]-d1, encoded2[j][1]-d2);
            int cal=encoded1[i][0]*encoded2[j][0];
            if (ans.size()>=1 and ans[ans.size()-1][0]==cal) ans[ans.size()-1][1]+=index;
            else ans.push_back({cal,index});
            d1+=index;
            d2+=index;
            if (encoded1[i][1]-d1==0) i++, d1=0;
            if(encoded2[j][1]-d2==0) j++, d2=0;
        }
        return ans;
    }
};
