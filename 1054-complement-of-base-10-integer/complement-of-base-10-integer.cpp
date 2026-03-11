class Solution {
public:
    int bitwiseComplement(int n) {
        int mask=0,m;
        m=n;
        if(n==0)
        {
            return 1;
        }
        while(m!=0)
        {
            mask=(mask<<1)|1;
            m=m>>1;;
        }
        int ans=(~n)&mask;
        return ans;
    }
};