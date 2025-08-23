class Solution {
public:
    int mod=1e9+7;
    long long solve(int x,long long n)
    {
        x=2;
        if(n==0)
        {
            return 1;
        }
        long long ans=1;
        ans=(solve(2,n/2))%mod;
        ans=(ans*ans)%mod;

        if(n%2)
        {
            ans=(2*ans)%mod;
        }
        return ans;
    }
    int monkeyMove(int n) {
        long long ans=solve(2,n)%mod;
        return (ans-2+mod)%mod;
    }
};