class Solution {
public:
    int solve(int index,vector<int>&dp,vector<int>&nums)
    {
        if(index==0)
        {
            return nums[0];
        }
        if(index<0)
        {
            return 0;
        }
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        int pick=nums[index]+solve(index-2,dp,nums);
        int notpick=solve(index-1,dp,nums);

        return dp[index]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n= nums.size();

        if(n==1)
        {
            return nums[0];
        }
        vector<int>a;
        vector<int>b;

        for(int i=0;i<n;i++)
        {
            if(i!=0)
            {
                a.push_back(nums[i]);
            }
            if(i!=n-1)
            {
                b.push_back(nums[i]);
            }
        }

        vector<int>dp1(n-1,-1);
        vector<int>dp2(n-1,-1);

        int type1=solve(n-2,dp1,a);
        int type2=solve(n-2,dp2,b);

        return max(type1,type2);

    }
};