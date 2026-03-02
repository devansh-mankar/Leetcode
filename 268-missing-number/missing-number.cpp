class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();

        int xorr=0;
        for(int i=1;i<=n;i++)
        {
            xorr=xorr^i;
        }
        for(int i=0;i<n;i++)
        {
            xorr=xorr^nums[i];
        }
        return xorr;
    }
};