
class Solution {
public:
    vector<vector<int>> dir={{-1,0},{0,-1},{1,0},{0,1}};
    int islandPerimeter(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int ans=0;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                int temp=0;
                if(grid[i][j]==1){
                temp=4;
                for(auto it: dir){
                    if (i+it[0]<=row-1 and i+it[0]>=0 and j+it[1]>=0 and j+it[1]<=col-1){
                        if(grid[i+it[0]][j+it[1]]==1) temp-=1;
                    }
                 }
                }
                ans+=temp;
            }
        }
        return ans;
    }
};
