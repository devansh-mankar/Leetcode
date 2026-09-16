class Solution {
public:
    int mod=1e9+7;
    long long solve(long long x,long long n)
    {
        if(n==0) return 1;

        if(n%2==0)
        {
            long long x1=(x*x)%mod;
            return solve(x1,n/2)%mod;
        }

        return (x*solve(x,n-1))%mod;
    }
    int countGoodNumbers(long long n) {
        long long even=n/2+n%2;
        long long odd=n/2;

        return (solve(5,even)*solve(4,odd))%mod;
    }
};