class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev=nums[0],prev2=0;

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
};