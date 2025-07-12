class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>&grid)
    {
        if(row<0 || row>=grid.size() || col<0 || col>=grid[0].size() || grid[row][col]!=1)
        {
            return;
        }
        grid[row][col]=2;
        dfs(row-1,col,grid);
        dfs(row,col+1,grid);
        dfs(row+1,col,grid);
        dfs(row,col-1,grid);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || i==n-1 || j==0 || j==m-1)
                {
                    if(grid[i][j]==1)
                    {
                        dfs(i,j,grid);
                    }
                }
            }
        }

        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    count++;
                }
            }
        }
        return count;
    }
};