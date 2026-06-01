class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int>nums(n);
        int xorr=0;
        for(int i=0;i<n;i++)
        {
            nums[i]=start+2*i;
            xorr=xorr^nums[i];
        }
        return xorr;
        
    }
};