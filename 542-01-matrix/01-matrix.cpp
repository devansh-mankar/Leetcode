class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>dis(n,vector<int>(m,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({i,j});
                    dis[i][j]=0;
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
            if(nr>=0 && nr<n && nc>=0 && nc<m && dis[nr][nc]==-1)
            {
                q.push({nr,nc});
                dis[nr][nc]=dis[row][col]+1;
            }
            }
        }
        return dis;
    }
};