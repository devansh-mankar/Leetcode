class Solution {
public:
    int BinarySearch(vector<int>&arr,int n,int x)
    {
        if(arr[0]>x)
        {
            return 0;
        }
        int s=0,e=n-1;

        while(s<=e)
        {
            int mid=s+(e-s)/2;

            if(arr[mid]==x)
            {
                return mid;
            }
            if(arr[mid]<x)
            {
                s=mid+1;
            }
            else
            {
                e=mid-1;
            }
        }
        return s;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>ans;
        int n=arr.size();
        int pos=BinarySearch(arr,n,x);
        int i=pos-1,j=pos;

        while(k>0 && i>=0 && j<n)
        {
            if(abs(x-arr[i])<=abs(arr[j]-x))
            {
                ans.push_back(arr[i--]);
            }
            else
            {
                ans.push_back(arr[j++]);
            }
            k--;
        } 

        //for edge cases
        while(k--)
        {
            if(i<0)
            {
                ans.push_back(arr[j++]);
            }
            else if(j>=n)
            {
                ans.push_back(arr[i--]);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};