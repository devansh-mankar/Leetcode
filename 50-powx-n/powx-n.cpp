class Solution {
public:
    double myPow(double x, int n) {
        double res=1;
        long long power=n;

        if(power<0)
        {
            power=-1*power;
        }

        while(power)
        {
            if(power%2)
            {
                res=res*x;
                power--;
            }
            else{
                x=x*x;
                power/=2;
            }
        }

        if(n<0)
        {
            return 1/res;
        }
        return res;
    }
};