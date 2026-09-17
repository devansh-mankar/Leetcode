class Solution {
public:
    int mod=1e9+7;
    long long solve(long long x,long long n)
    {
        if(x==1 || n==0) return 1;

        if(n%2==0)
        {
            long long x1=(x*x)%mod;
            return solve(x1,n/2)%mod;
        }
        return x*solve(x,n-1)%mod;
    }
    int countGoodNumbers(long long n) {
        long long odd=n/2;
        long long even=n/2+n%2;
        if(n==1) return 5;

        return (solve(4,odd)*solve(5,even))%mod;
    }
};