//79. Word Search
class Solution {
public:
    int dir[4][2]={{0,1}, {0,-1},{1,0}, {-1,0}};
    vector<vector<char>> grid;
    int m,n;
    bool exist(vector<vector<char>>& board, string word) {
        m=board.size();
        n=board[0].size();
        grid=board;
        if(word.length()>m*n) return false;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]==word[0]){
                    if(dfs_backtracking(i, j, word, 0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    
    bool dfs_backtracking(int x_coord, int y_coord, string& word, int index){
        bool res=false;
        if(index==word.size()-1)
            return true;
        char temp=grid[x_coord][y_coord];
        grid[x_coord][y_coord]='*';
        for(auto it: dir){
            int dx=x_coord+it[0];
            int dy=y_coord+it[1];
            if(dx>=0 and dx<m and dy>=0 and dy<n and grid[dx][dy]==word[index+1]){
                 res|= dfs_backtracking(dx, dy, word, index+1);
                if(res)
                   break;}
        }
        grid[x_coord][y_coord]=temp;
        return res;
    }
};
