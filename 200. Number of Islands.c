class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0, islands = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    eraseIslands(grid, i, j);
                }
            }
        }
        return islands;
    }
private:
    void eraseIslands(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i == m || j < 0 || j == n || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';
        eraseIslands(grid, i - 1, j);
        eraseIslands(grid, i + 1, j);
        eraseIslands(grid, i, j - 1);
        eraseIslands(grid, i, j + 1);
    }
};

/*8/25풀이
class Solution {
public:
    vector<vector<int>> Dir={{0,1}, {1, 0}, {-1, 0}, {0,-1}};
    int ans=0;
    int numIslands(vector<vector<char>>& grid) {
        for(int i=0; i<grid.size(); i++)
            for(int j=0; j<grid[0].size(); j++)
                DFSsearch(i, j, grid, false, ans);
        return ans;
    }
    void DFSsearch(int x, int y, vector<vector<char>>& grid, bool cont, int& ans){
        if(grid[x][y]=='1'){
            grid[x][y]='0';
            if (cont!=true) ans++;
            for(auto it: Dir){
                int dx=x+it[0];
                int dy=y+it[1];
                if(dx>=0 and dx<=grid.size()-1 and dy>=0 and dy<=grid[0].size()-1)
                    DFSsearch(dx, dy, grid, true, ans);    
            }
            cont=false;
        }
        return;
    }
};

/*9/21 풀이
class Solution {
public:
    vector<vector<int>> dir={{0,-1},{1,0},{0,1},{-1,0}};
    int numIslands(vector<vector<char>>& grid){
        int ans=0;
        for(int i=0; i<grid.size();i++){
            for(int j=0; j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    remapBFS(i, j, grid);
                    ans++;
                }
            }
        }
    return ans;
}

    void remapBFS(int row, int col, vector<vector<char>>&grid){
        queue<pair<int, int>> q;
        q.push({row, col});
        while(!q.empty()){
            auto qpop=q.front();
            q.pop();
            grid[qpop.first][qpop.second]='0'; //Remap
            for(int i=0; i<dir.size(); i++){
                int dx=qpop.first+dir[i][0];
                int dy=qpop.second+dir[i][1];
                if(dx>=0 and dx<grid.size() and dy>=0 and dy<grid[0].size() and grid[dx][dy]=='1'){
                    grid[dx][dy]='0';
                    q.push({dx, dy});
                }
            }
        }
    }
        
};
