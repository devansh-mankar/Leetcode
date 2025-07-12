class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<int,int>>q;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || i==n-1 || j==0 || j==m-1)
                {
                    if(grid[i][j]==1)
                    {
                        grid[i][j]=2;
                    q.push({i,j});
                    }
                    
                }
            }
        }

        vector<int>dr={-1,0,1,0};
        vector<int>dc={0,1,0,-1};

        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            for(int i=0;i<4;i++)
            {
                int nr=row+dr[i];
                int nc=col+dc[i];
            
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1)
            {
                q.push({nr,nc});
                grid[nr][nc]=2;
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