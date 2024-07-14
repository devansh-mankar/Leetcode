class Solution {
public:
    int solve(vector<int>&nums)
    {
        int n=nums.size();
        int prev2=0,prev=nums[0];

        for(int i=1;i<n;i++)
        {
            int pick=nums[i];
            if(i>1)
            {
                pick+=prev2;
            }
            int notpick=prev;
            int curr=max(pick,notpick);
            prev2=prev;
            prev=curr;
        }
        return prev;
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