class Solution {
public:
    int mod=1e9+7;
    long long solve(long long x,long long n)
    {
        if(n==0)
        {
            return 1;
        }
        long long ans=1;
        ans=(solve(x,n/2))%mod;
        ans=(ans*ans)%mod;
        if(n%2)
        {
            ans=(x*ans)%mod;
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        long long odd=n/2;
        long long even=n/2+n%2;

        return (solve(5,even)*solve(4,odd))%mod;
    }
};