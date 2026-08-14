class Solution {
public:
    int solve(vector<int>&arr,int k)
    {
        int n=arr.size();
        int low=0;
        int high=n-1;
        int res=n;

        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(arr[mid]>=k)
            {
                res=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return res;
    }
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        for(int i=0;i<n;i++)
        {
            sort(mat[i].begin(),mat[i].end());
        }

        int cntMax=-1;
        int index=-1;

        for(int i=0;i<n;i++)
        {
            int count=m-solve(mat[i],1);
            if(cntMax<count)
            {
                cntMax=count;
                index=i;
            }
        }
        return {index,cntMax};
    }
};