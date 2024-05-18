class Solution {
public:
    int countSubarrays(vector<int>&nums,int limit)
    {
        //sort(nums.begin(),nums.end());
        int count=1;
        int n=nums.size();
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            if(sum+nums[i]<=limit)
            {
                sum+=nums[i];
            }
            else
            {
                count++;
                sum=nums[i];
            }
        }
        return count;
        
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);

        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(countSubarrays(nums,mid)>k)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return low;
    }
};