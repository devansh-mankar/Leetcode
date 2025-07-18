class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        pq.push({0,{0,0}});

        vector<int>dr={-1,0,1,0};
        vector<int>dc={0,1,0,-1};
        dist[0][0]=0;

        while(!pq.empty())
        {
            int diff=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();

            if(row==n-1 && col==m-1)
            {
                return diff;
            }

            for(int i=0;i<4;i++)
            {
                int nr=row+dr[i];
                int nc=col+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m)
                {
                    int neff=max(diff,abs(heights[nr][nc]-heights[row][col]));
                    if(neff<dist[nr][nc])
                    {
                        dist[nr][nc]=neff;
                        pq.push({neff,{nr,nc}});
                    }
                }
            }
        }
        return -1;
    }
};