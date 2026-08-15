class Solution {
public:
    bool solve(int row,int col,vector<vector<int>>&matrix,int k)
    {
        if(row>=matrix.size() || col<0) return 0;
        if(matrix[row][col]>k) return solve(row,col-1,matrix,k);
        else if(matrix[row][col]<k) return solve(row+1,col,matrix,k);

        return matrix[row][col]==k;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix[0].size();

        return solve(0,m-1,matrix,target);
    }
};