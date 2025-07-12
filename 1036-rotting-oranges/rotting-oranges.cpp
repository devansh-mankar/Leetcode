class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;

        int countFresh=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    vis[i][j]=true;
                }
                else if(grid[i][j]==1)
                {
                    countFresh++;
                }
            }
        }


        int count=0,time=0;
        vector<int>dr={-1,0,1,0};
        vector<int>dc={0,1,0,-1};

        while(!q.empty())
        {
            int row=q.front().first.first;
            int col=q.front().first.second;
            int t=q.front().second;
            q.pop();
            time=max(time,t);

            for(int i=0;i<4;i++)
            {
                int nr=row+dr[i];
                int nc=col+dc[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]==1)
                {
                    vis[nr][nc]=true;
                    count++;
                    q.push({{nr,nc},t+1});
                }
            }
        }

        if(count!=countFresh)
        {
            return -1;
        }
        return time;
    }
};