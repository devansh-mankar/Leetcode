class Solution {
public:
    vector<int>dr={-1,0,1,0};
    vector<int>dc={0,1,0,-1};
    vector<vector<int>>distance(vector<vector<int>>&grid)
    {
        int n=grid.size();
        vector<vector<int>>dis(n,vector<int>(n,INT_MAX));
        queue<pair<int,int>>q;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j])
                {
                    dis[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty())
        {
            auto temp=q.front();
            q.pop();
            int row=temp.first;
            int col=temp.second;
            for(int i=0;i<4;i++)
            {
                int nr=row+dr[i];
                int nc=col+dc[i];

                if((nr>=0 && nr<n) && (nc>=0 && nc<n) && dis[nr][nc]==INT_MAX)
                {
                    dis[nr][nc]=dis[row][col]+1;
                    q.push({nr,nc});
                }
            }
        }
        return dis;
        
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0] || grid[n-1][n-1])
        {
            return 0;
        }
        vector<vector<int>>dist=distance(grid);
        vector<vector<int>>vis(n,vector<int>(n,0));
        priority_queue<pair<int,pair<int,int>>>pq;

        vector<int>dr={-1,0,1,0};
        vector<int>dc={0,1,0,-1};

        pq.push({dist[0][0],{0,0}});
        vis[0][0]=1;

        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();

            int ds=it.first;
            int row=it.second.first;
            int col=it.second.second;

            if(row==n-1 && col==n-1)
            {
                return ds;
            }

            for(int i=0;i<4;i++)
            {
                int nr=row+dr[i];
                int nc=col+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<n && !vis[nr][nc] && grid[nr][nc]!=1)
                {
                    vis[nr][nc]=1;
                    int ds1=dist[nr][nc];
                    pq.push({min(ds,ds1),{nr,nc}});
                }
            }
        }
    return 0;

    }
};