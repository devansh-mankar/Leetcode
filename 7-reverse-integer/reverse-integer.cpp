class Solution {
public:
    int reverse(int x) {
        long long rev=0;
        
        while(x)
        {
            int rem=x%10;
            rev=rev*10+rem;

            if(rev>INT_MAX || (rem>7 && rev>INT_MAX/10))
            {
                return 0;
            }
            if(rev<INT_MIN || (rem<-8 && rev<INT_MIN/10))
            {
                return 0;
            }
            x=x/10;
        }
        return rev;
    }
};