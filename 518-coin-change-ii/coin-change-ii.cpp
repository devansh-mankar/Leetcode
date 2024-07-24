class Solution {
public:
    int solve(int index,int amount,vector<int>&coins,vector<vector<int>>&dp)
    {
        if(index==0)
        {
            return (amount%coins[0]==0);
        }
        if(dp[index][amount]!=-1)
        {
            return dp[index][amount];
        }
        int notpick=solve(index-1,amount,coins,dp);
        int pick=0;
        if(coins[index]<=amount)
        {
            pick=solve(index,amount-coins[index],coins,dp);
        }
        return dp[index][amount]=(pick+notpick);
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return solve(n-1,amount,coins,dp);
    }
};