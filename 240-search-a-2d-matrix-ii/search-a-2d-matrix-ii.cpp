class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();

        int row=0;
        int col=m-1;
        //think of it as some form of spiral matrix we are reaching there by reducing the row or column
        while(row<n && col>=0)
        {
            if(matrix[row][col]==target)
            {
                return true;
            }
            else if(matrix[row][col]>target)
            {
                col--;
            }
            else{
                row++;
            }
        }
        return false;

    }
};