class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m, vector<int>(n,0));
        queue<pair<int, int>> q;
        vector<pair<int, int>> dirs = {make_pair(0,1), make_pair(1,0)};
        grid[0][0] = 1;
        q.push(make_pair(0,0));
        while(q.size() > 0) {
            pair<int, int> cell = q.front();
            q.pop();
            int next_value = grid[cell.first][cell.second];
            for(auto &p: dirs) {
                if ((p.second + cell.second) > n-1  || 
                   (p.first + cell.first) > m-1) continue;
                pair<int, int> next_cell = make_pair(p.first+cell.first, p.second+cell.second);
                if (grid[next_cell.first][next_cell.second] == 0)
                    q.push(next_cell);
                grid[next_cell.first][next_cell.second] += next_value;
            }
        }
        return grid[m-1][n-1];
    }
};

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                dp[i][j]=dp[i-1][j]+ dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
        
    }
};
