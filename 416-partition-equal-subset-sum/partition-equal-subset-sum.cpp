class Solution {
public:
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
            vector<int>prev(k1+1,0);
            prev[0]=true;
            if(nums[0]<=k1)
            {
                prev[nums[0]]=true;
            }

            for(int i=1;i<n;i++)
            {
                vector<int>curr(k1+1,0);
                curr[0]=0;
                for(int j=0;j<=k1;j++)
                {
                    bool notpick=prev[j];
                    bool pick=false;
                    if(nums[i]<=j)
                    {
                        pick=prev[j-nums[i]];
                    }
                    curr[j]=pick || notpick;
                }
                prev=curr;
            }
            return prev[k1];
        }
    }
};