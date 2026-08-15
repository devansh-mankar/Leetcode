class Solution {
public:
    int findOnes(vector<int>&arr,int k)
    {
        int low=0;
        int high=arr.size()-1;
        int res=arr.size();

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
        int maxi=-1;
        int index=-1;
        for(int i=0;i<n;i++)
        {
            int count=m-findOnes(mat[i],1);
            if(maxi<count)
            {
                maxi=count;
                index=i;
            }
        }
        return {index,maxi};
    }
};