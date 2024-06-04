class Solution {
public:
    int solve(vector<int>&nums,int k)
    {
        if(k<0)
        {
            return 0;
        }
        int left=0,right=0,count=0;
        int n=nums.size();
        int sum=0;
        while(right<n)
        {
            sum+=nums[right]%2;
            while(sum>k)
            {
                sum-=nums[left]%2;
                left++;
            }
            if(sum<=k)
            {
                count+=right-left+1;
            }
            right++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};