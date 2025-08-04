class Solution {
public:
    int countPrimes(int n) {
        if(n<=2)
        {
            return 0;
        }
        int count=0;
        vector<int>primes(n+1,1);
        primes[0]=primes[1]=0;

        for(int i=2;i<n;i++)
        {
            if(primes[i]==1)
            {
                count++;
                for(int j=2*i;j<=n;j+=i)
                {
                    primes[j]=0;
                }
            }
        }
        return count;
    }
};