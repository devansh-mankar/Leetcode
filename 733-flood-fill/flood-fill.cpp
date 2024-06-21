class Solution {
public:
    void solve(int row,int col,int color,vector<vector<int>>&temp,vector<vector<int>>&image)
    {
        temp[row][col]=color;
        int n=image.size();
        int m=image[0].size();

        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        for(int i=0;i<4;i++)
        {
            int nrow=row+dr[i];
            int ncol=col+dc[i];

        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==image[row][col] && temp[nrow][ncol]!=color)
            {
                solve(nrow,ncol,color,temp,image);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();

        vector<vector<int>>temp=image;
        solve(sr,sc,color,temp,image);
        return temp;
    }
};