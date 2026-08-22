class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int num=n;
        int prod=1;

        while(num)
        {
            sum+=(num%10);
            prod=prod*(num%10);
            num/=10;
        }

        return (n%(sum+prod)==0);
    }
};