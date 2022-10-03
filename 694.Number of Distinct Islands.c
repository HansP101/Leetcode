class Solution {
private:
     unordered_map< int, vector<pair<int,int>>> map;   
    
public:
    
    void dfs(vector<vector<int>>& grid,int row,int col,vector<vector<bool>>& visited, int counter)
    {
        visited[row][col] = true;
        int rowOffset[4] = {0,0,1,-1};
        int colOffset[4] = {1,-1,0,0};
        int px,py;
        int m = grid.size();
        int n = grid[0].size();
       
       map[counter].push_back(make_pair(row,col));//making the map with index:#of island in q.200, value is row and column pair
        
        for(int i=0;i<4;i++)
        {
            px = row + rowOffset[i];
            py = col + colOffset[i];
            
            if(px>=0 && px<=m-1 && py>=0 && py<=n-1)
            {
                if(grid[px][py]=='1' && !visited[px][py])
                    dfs(grid, px, py, visited,counter);
            }    
        }
    }
    int numDistinctIslands(vector<vector<int>>& grid) {
        if(grid.empty())
        {
            return 0;
        }
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>> visited (m,vector<bool>(n,false));
        int counter=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1 && !visited[i][j])
                {
                    counter++;
                    dfs(grid,i,j,visited, counter);
                }
            }
        }
        return  removeNonDistict(map); //Need remove duplicate
    }
    int removeNonDistict(unordered_map<int, vector<pair<int,int>>> &map)
    {
        if(map.empty())
            return 0;
        for(auto &x:map)
        {
            int initialRow=x.second[0].first;
            int initialcol=x.second[0].second;
            for(auto &coord:x.second)
            {      
                //first value on the map is the offset value of the island for the relative coordinate.
                coord.first-=initialRow; //adjust the location.
                coord.second-=initialcol;
            }
        }
        set<vector<pair<int,int>> >saveDistict;
        for (auto &it:map)
        {
            saveDistict.insert(it.second);  // value not yet encountered => remeber it
        }    
        return saveDistict.size();
    }
};
