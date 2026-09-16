class Solution {
public:
    double solve(double x,long long n)
    {
        if(n==0 || x==1) return 1.0;

        if(n%2==0) return solve(x*x,n/2);

        return x*solve(x,n-1);
    }
    double myPow(double x, int n) {
        long long N=n;

        if(n<0)
        {
            x=1/x;
            N=1LL*-1*n;
        }
        return solve(x,N);
    }
};