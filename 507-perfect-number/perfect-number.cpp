class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num<=1)
        {
            return 0;
        }
        int sum=1;
        for(int i=2;i*i<=num;i++)
        {
            if(num%i==0)
            {
                sum+=i;
                if(num/i!=i) sum+=(num/i);
            }
        }
        return sum==num;
    }
};