class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<int>>&grid)
    {
        if(row<0 || row>=grid.size() || col<0 || col>=grid[0].size() || vis[row][col] || grid[row][col]!=1)
        {
            return;
        }
        vis[row][col]=true;
        dfs(row+1,col,vis,grid);
        dfs(row-1,col,vis,grid);
        dfs(row,col-1,vis,grid);
        dfs(row,col+1,vis,grid);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || i==n-1 || j==0 || j==m-1)
                {
                    if(grid[i][j]==1)
                    {
                        dfs(i,j,vis,grid);
                    }
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]==1)
                {
                    count++;
                }
            }
        }
        return count;
    }
};