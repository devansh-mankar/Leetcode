class Solution {
public:
    void dfs(int row,int col,int color,int original,vector<vector<int>>&image)
    {
        if(row<0 || row>=image.size() || col<0 || col>=image[0].size() || image[row][col]!=original || image[row][col]==color)
        {
            return;
        }
        image[row][col]=color;
        dfs(row-1,col,color,original,image);
        dfs(row,col+1,color,original,image);
        dfs(row+1,col,color,original,image);
        dfs(row,col-1,color,original,image);

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int original=image[sr][sc];
        dfs(sr,sc,color,original,image);
        return image;
    }
};