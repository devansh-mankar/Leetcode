class Solution {
public:
    bool BinarySearch(vector<int>&temp,int k)
    {
        int low=0;
        int high=temp.size()-1;

        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(temp[mid]==k)
            {
                return true;
                break;
            }
            else if(temp[mid]>k)
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
           if(BinarySearch(matrix[i],target))
           {
            return true;
           }
        }
        return false;
    }
};