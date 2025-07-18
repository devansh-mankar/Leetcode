class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1)
        {
            return -1;
        }
        queue<pair<int,int>>q;
        q.push({0,0});

        grid[0][0]=1;
        vector<int>dr={-1,0,1,0,1,1,-1,-1};
        vector<int>dc={0,1,0,-1,1,-1,1,-1};
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            int currd=grid[row][col];
            if(row==n-1 && col==n-1)
            {
                return currd;
            }
            for(int i=0;i<8;i++)
            {
                int nr=row+dr[i];
                int nc=col+dc[i];

                if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==0)
                {
                    grid[nr][nc]=currd+1;
                    q.push({nr,nc});
                }
            }
        }
        return -1;
    }
};