class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();

        int original=image[sr][sc];
        image[sr][sc]=color;

        queue<pair<int,int>>q;
        q.push({sr,sc});

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

            if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc]==original && image[nr][nc]!=color)
            {
                q.push({nr,nc});
                image[nr][nc]=color;
            }
            }
        }
        return image;
    }
};