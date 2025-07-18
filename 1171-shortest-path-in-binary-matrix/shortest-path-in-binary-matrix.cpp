class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();

        if(grid[0][0]==1)
        {
            return -1;
        }
        
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        pq.push({1,{0,0}});
        dist[0][0]=1;
        vector<int>dr={-1,0,1,0,1,1,-1,-1};
        vector<int>dc={0,1,0,-1,1,-1,-1,1};
        while(!pq.empty())
        {
            int d=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();

            if(row==n-1 && col==n-1)
            {
                return d;
            }
            for(int i=0;i<8;i++)
            {
                int nr=row+dr[i];
                int nc=col+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==0)
                {
                    int newd=dist[row][col]+1;
                    if(dist[nr][nc]>newd)
                    {
                        dist[nr][nc]=newd;
                        pq.push({newd,{nr,nc}});
                    }
                    
                }
            }
        }
        return -1;
    }
};