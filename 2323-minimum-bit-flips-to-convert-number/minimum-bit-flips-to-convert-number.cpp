class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorr=start^goal;
        int count=0;
        while(xorr)
        {
            if(xorr&1)
            {
                count++;
            }
           xorr= xorr>>1;
        }
        return count;
    }
};