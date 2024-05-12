class Solution {
public:
    void merge(int low,int mid,int high,vector<int>&nums)
    {
        int n=nums.size();
        int left=low;
        int right=mid+1;
        vector<int>temp;

        while(left<=mid && right<=high)
        {
            if(nums[left]<=nums[right])
            {
                temp.push_back(nums[left++]);
            }
            else
            {
                temp.push_back(nums[right++]);
            }
        }

        while(left<=mid)
        {
            temp.push_back(nums[left++]);
        }
        while(right<=high)
        {
            temp.push_back(nums[right++]);
        }

        for(int i=low;i<=high;i++)
        {
            nums[i]=temp[i-low];
        }
    }
    int countPairs(int low,int mid,int high,vector<int>&nums)
    {
        int right=mid+1;
        int count=0;
        for(int i=low;i<=mid;i++)
        {
            while(right<=high && nums[i]>2*(long long)nums[right])
            {
                right++;
            }
            count+=(right-(mid+1));
        }
        return count;
    }
    int mergeSort(int s,int e,vector<int>&nums)
    {
        int cnt=0;
        if(s>=e)
        {
            return cnt;
        }
        int mid=s+(e-s)/2;
        cnt+=mergeSort(s,mid,nums);
        cnt+=mergeSort(mid+1,e,nums);
        cnt+=countPairs(s,mid,e,nums);
        merge(s,mid,e,nums);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
     int n=nums.size();
    return mergeSort(0,n-1,nums);   
    }
};