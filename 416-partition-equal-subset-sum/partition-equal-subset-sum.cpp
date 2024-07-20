class Solution {
public:
    bool solve(int index,int k,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(k==0)
        {
            return true;
        }
        if(index==0)
        {
            return nums[0]==k;
        }
        if(dp[index][k]!=-1)
        {
            return dp[index][k];
        }
        bool notpick=solve(index-1,k,nums,dp);
        bool pick=false;
        if(nums[index]<=k)
        {
            pick=solve(index-1,k-nums[index],nums,dp);
        }
        return dp[index][k]=pick || notpick;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int k=accumulate(nums.begin(),nums.end(),0);

        if(k%2==1)
        {
            return false;
        }
        else
        {
            int k1=k/2;
            vector<vector<int>>dp(n,vector<int>(k1+1,-1));
            return solve(n-1,k1,nums,dp);
        }
    }
};