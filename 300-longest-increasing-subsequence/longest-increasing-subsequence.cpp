class Solution {
public:
    int solve(int index,int n,int prev,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(index==n)
        {
            return 0;
        }
        if(dp[index][prev+1]!=-1)
        {
            return dp[index][prev+1];
        }
        int notpick=solve(index+1,n,prev,nums,dp);
        int pick=0;
        if(prev==-1 || nums[index]>nums[prev])
        {
            pick=1+solve(index+1,n,index,nums,dp);
        }
        return dp[index][prev+1]= max(pick,notpick);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(0,n,-1,nums,dp);
    }
};