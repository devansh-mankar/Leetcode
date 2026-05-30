class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size();
        long long xorr=0;

        for(int i=0;i<n;i++)
        {
            xorr=xorr^nums[i];
        }

        long long rightmost=xorr&(-xorr);

        int xorr1=0;
        int xorr2=0;
        for(int i=0;i<n;i++)
        {
            if(rightmost&nums[i])
            {
                xorr1=xorr1^nums[i];
            }
            else{
                xorr2=xorr2^nums[i];
            }
        }
        return {xorr1,xorr2};
    }
};