class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int res = 1;
    int row = grid.size();
    if (row == 0) return -1;
    int col = grid[0].size();
    if (col == 0 ) return -1;
    if (grid[0][0] != 0 || grid[row-1][col-1] != 0) return -1;

        queue<pair<int, int>> queue;
        queue.push(make_pair(0,0));
        vector<vector<int>> directions = {{1,1}, {0,1},{1,0},{0,-1},{-1,0},{-1, -1},{1, -1},{-1, 1}};
        grid[0][0] = 1;
        while(!queue.empty()){
            auto curr = queue.front();
            int x = curr.first, y = curr.second;
            if( x == row -1 && y == col -1) return grid[x][y];

            for(auto direction : directions){
                int nx = x + direction[0];
                int ny = y + direction[1];
                if(nx >= 0 && nx < row && ny >= 0 && ny < col && grid[nx][ny] == 0){
                    queue.push(make_pair(nx,ny));
                    grid[nx][ny] = grid[x][y] + 1;
                }
            }
            queue.pop();
        }
        return -1;
        
    }
};

class Solution {
public:
    struct coord{
        int x;
        int y;
        int steps;
    };
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
       
        int row = grid.size();
        if (row == 0) return -1;
        int col = grid[0].size();
        if (col == 0 ) return -1;
        if (grid[0][0] != 0 || grid[row-1][col-1] != 0) return -1;

            queue<coord> queue;
            queue.push({0,0,1});
            vector<vector<int>> directions = {{1,1}, {0,1},{1,0},{0,-1},{-1,0},{-1, -1},{1, -1},{-1, 1}};
            grid[0][0] = 1;
            while(!queue.empty()){
                auto curr = queue.front();
                int x = curr.x, y = curr.y;
                if( x == row -1 && y == col -1) return curr.steps;

                for(auto it : directions){
                    int nx = x + it[0];
                    int ny = y + it[1];
                    if(nx >= 0 && nx < row && ny >= 0 && ny < col && grid[nx][ny] == 0){
                        queue.push({nx,ny,curr.steps+1});
                        grid[nx][ny] = 1;
                    }
                }
                queue.pop();
            }
            return -1;    
    }
};
