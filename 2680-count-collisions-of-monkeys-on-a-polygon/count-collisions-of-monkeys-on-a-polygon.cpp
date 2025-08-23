class Solution {
public:
    int mod=1e9+7;
    long long solve(long long n)
    {
        long long ans=1;
        long long base=2;
        while(n)
        {
            if(n%2)
            {
                ans=(ans*base)%mod;
            }
            base=(base*base)%mod;
            n=n/2;
        }
        return ans;
    }
    int monkeyMove(int n) {
        long long ans=solve(n);
        return (ans-2+mod)%mod;
    }
};