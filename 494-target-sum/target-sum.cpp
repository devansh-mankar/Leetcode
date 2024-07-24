class Solution {
public:
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
        vector<vector<int>>dp(n,vector<int>(k+1,0));
        if(nums[0]==0)
        {
            dp[0][0]=2;
        }
        else
        {
            dp[0][0]=1;
        }

        if(nums[0]!=0 && nums[0]<=k)
        {
            dp[0][nums[0]]=1;
        }


        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=k;j++)
            {
                int notpick=dp[i-1][j];
                int pick=0;
                if(nums[i]<=j)
                {
                    pick=dp[i-1][j-nums[i]];
                }
                dp[i][j]=(pick+notpick);
            }
        }

        return dp[n-1][k];

    }
};