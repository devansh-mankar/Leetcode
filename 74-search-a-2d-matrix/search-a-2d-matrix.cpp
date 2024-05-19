class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size();
        int c=matrix[0].size();

        int low=0,high=(r*c)-1;

        while(low<high)
        {
            int mid=low+(high-low)/2;
            if(matrix[mid/c][mid%c]<target)
            {
                low=mid+1;
            }
            else
            {
                high=mid;
            }
        }
        return matrix[high/c][high%c]==target;
    }
};