class Solution {
public:
    int solve(vector<int>&nums)
    {
        int n=nums.size();
        vector<int>dp(n,0);
        dp[0]=nums[0];

        for(int i=1;i<n;i++)
        {
            int pick=nums[i];
            if(i>1)
            {
                pick+=dp[i-2];
            }
            int notpick=dp[i-1];

            dp[i]=max(pick,notpick);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>a;
        vector<int>b;
        if(n==1)
        {
            return nums[0];
        }

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

        int type1=solve(a);
        int type2=solve(b);

        return max(type1,type2);
    }
};