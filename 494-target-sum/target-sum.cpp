class Solution {
public:
    int solve(int index,vector<int>&nums,int k,vector<vector<int>>&dp)
    {
        if(index==0)
        {
            if(k==0 && nums[0]==0)
            {
                return 2;
            }
            if(k==0 || nums[0]==k)
            {
                return 1;
            }
            return 0;
        }
        if(dp[index][k]!=-1)
        {
            return dp[index][k];
        }
        int notpick=solve(index-1,nums,k,dp);
        int pick=0;
        if(nums[index]<=k)
        {
            pick=solve(index-1,nums,k-nums[index],dp);
        }
        return dp[index][k]=(pick+notpick);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int total=accumulate(nums.begin(),nums.end(),0);
        if((total-target)<0)
        {
            return 0;
        }
        if((total-target)%2==1)
        {
            return 0;
        }
        int k=(total-target)/2;
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return solve(n-1,nums,k,dp);
    }
};