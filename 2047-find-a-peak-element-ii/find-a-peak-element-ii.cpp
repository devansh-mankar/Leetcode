class Solution {
public:
    int findIndex(vector<vector<int>>&mat,int mid)
    {
        int n=mat.size();
        int index=-1;
        int maxi=-1;

        for(int i=0;i<n;i++)
        {
            if(mat[i][mid]>maxi)
            {
                maxi=mat[i][mid];
                index=i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        int low=0;
        int high=m-1;

        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int maxRowIndex=findIndex(mat,mid);

            int left=mid-1>=0 ? mat[maxRowIndex][mid-1]:-1;
            int right=mid+1<m ? mat[maxRowIndex][mid+1]:-1;

            if(mat[maxRowIndex][mid]>left && mat[maxRowIndex][mid]>right)
            {
                return {maxRowIndex,mid};
            }
            else if(mat[maxRowIndex][mid]<left)
            {
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return {-1,-1};
    }
};