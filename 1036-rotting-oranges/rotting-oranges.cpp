class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>&grid,int min=2)
    {
        if(row<0 || row>=grid.size() || col<0 || col>=grid[0].size() || grid[row][col]==0 || grid[row][col]>1 && grid[row][col]<min)
        {
            return;
        }

        grid[row][col]=min;
        dfs(row-1,col,grid,min+1);
        dfs(row,col+1,grid,min+1);
        dfs(row+1,col,grid,min+1);
        dfs(row,col-1,grid,min+1);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    dfs(i,j,grid);
                }
            }
        }
        int mini=2;
        for(auto i:grid)
        {
            for(auto j:i)
            {
                if(j==1)
                {
                    return -1;
                }
                mini=max(mini,j);
            }
        }
        return mini-2;
    }
};