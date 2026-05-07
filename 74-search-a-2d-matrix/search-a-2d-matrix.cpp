class Solution {
public:
    bool BinarySearch(vector<int>&temp,int target)
    {
        int n=temp.size();
        int low=0;
        int high=n-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(temp[mid]==target)
            {
                return true;
                break;
            }
            else if(temp[mid]>target)
            {
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();

        for(int i=0;i<n;i++)
        {
            if(matrix[i][0]<=target && matrix[i][m-1]>=target)
            {
                return BinarySearch(matrix[i],target);
            }
        }
        return false;
    }
};