class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));

        int countFresh=0;
        queue<pair<pair<int,int>,int>>q;
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
        int time=0,count=0;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        while(!q.empty())
        {
            int row=q.front().first.first;
            int col=q.front().first.second;
            int t=q.front().second;
            q.pop();
            time=max(t,time);

            for(int i=0;i<4;i++)
            {
                int nrow=dr[i]+row;
                int ncol=dc[i]+col;

            if((nrow>=0 && nrow<n) && (ncol>=0 && ncol<m) && (!vis[nrow][ncol]) && (grid[nrow][ncol]==1))
                {
                    count++;
                    vis[nrow][ncol]=true;
                    q.push({{nrow,ncol},t+1});
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