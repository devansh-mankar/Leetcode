class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xorr=0;

        int n=nums.size();
        for(int i=0;i<=n;i++)
        {
            xorr^=i;
        }

        for(int i=0;i<n;i++)
        {
            xorr^=nums[i];
        }
        return xorr;
    }
};