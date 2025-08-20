class Solution {
public:
    double solve(double x,long long power)
    {
        if(power==0)
        {
            return 1;
        }
        if(power%2)
        {
            return x*solve(x,power-1);
        }
        return solve(x*x,power/2);
    }
    double myPow(double x, int n) {
        if(n==0)
        {
            return 1;
        }
        long long power=n;
        if(power<0)
        {
            x=1/x;
            power=power*-1;
        }
        return solve(x,power);
    }
};