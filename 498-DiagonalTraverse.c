class Solution {
    /*
    
    규칙이 뭘까???
    0:(0,0)
    1:(0,1) (1,0)
    2:(2,0) (1,1) (0,2)
    3:(1,2) (2,1)
    4:(2,2)
    
    (0,0)(0,1)(0,2)(0,3)
    (1,0)(1,1)(1,2)(1,3)
    (2,0)(2,1)(2,2)(2,3)
    (3,0)(3,1)(3,2)(3,3)
    
    (0,0)
    (0,1)(1,0)
    (2,0)(1,1)(0,2)
    (0,3)(1,2)(2,1)(3,0)
    (3,1)(2,2)(1,3)
    (2,3)(3,2)
    (3,3)
    
    */
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int col=mat[0].size()-1;
        int row=mat.size()-1;
        int loopSize=row+col;
        int i=0, j=0;
        for(int loop=0; loop<=loopSize; loop++){
           for(int x=0; x<=loop; x++){
               i=x, j=loop-x;
               if(loop%2==0) swap(i,j);
               if(i<=row and j<=col)
                 ans.push_back(mat[i][j]);
           }
        }
        return ans;
    }
};
