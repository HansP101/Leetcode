
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int m=mat1.size();
        int n=mat2[0].size();
        assert(mat1[0].size()==mat2.size());
        vector<vector<int>> ans(m, vector<int> (n, 0));
        for(int i=0; i<mat1.size(); i++)
            for(int j=0; j<mat2[0].size(); j++)
                for(int k=0; k<mat1[0].size(); k++){
                     ans[i][j]+=mat1[i][k]*mat2[k][j];            
                }
        
        return ans;
    }
};
/* BETTER SOLUTION */
class Solution{
public:
  vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>&mat2){
      int m=mat1.size();
      int n=mat2[0].size();
      assert(mat1[0].size()==mat2.size());
      vector<vector<int>> ans(m, vector<int>(n, 0));
      unordered_map<int, vector<int>> nonZeroIndecesInB; //K:row V: columns
          
      for(int i=0; i<mat2.size(); i++){
          nonZeroIndecesInB[i]={};
          for(int j=0; j<mat2[0].size();j++){
              if(mat2[i][j]!=0) nonZeroIndecesInB[i].push_back(j);
          }
        }
      
      for(int i=0; i<m; i++)
              for(int k=0; k<mat1[0].size();k++)
                  if(mat1[i][k]!=0){
                      for(int j: nonZeroIndecesInB[k])
                          ans[i][j]+=mat1[i][k]*mat2[k][j];
                      
                  }

      return ans;
  }
};
