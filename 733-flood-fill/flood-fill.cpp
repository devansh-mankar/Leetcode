class Solution {
public:
    void solve(int row,int col,int color,int original,vector<vector<int>>&image)
    {
        if(row<0 || row>=image.size() || col<0 || col>=image[0].size() || image[row][col]==color || image[row][col]!=original)
        {
            return ;
        }
        image[row][col]=color;
        solve(row-1,col,color,original,image);
        solve(row,col+1,color,original,image);
        solve(row+1,col,color,original,image);
        solve(row,col-1,color,original,image);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       
      int original=image[sr][sc];
        solve(sr,sc,color,original,image);
        return image;
    }
};