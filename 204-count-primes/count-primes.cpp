class Solution {
public:
    int countPrimes(int n) {
        if(n<2) return 0;

        vector<int>primes;
        vector<int>isPrime(n+1,1);
        isPrime[0]=isPrime[1]=0;

        for(int i=2;i<n;i++)
        {
            if(isPrime[i])
            {
                primes.push_back(i);
            }
            for(auto p:primes)
            {
                if(1LL*i*p>n) break;

                isPrime[i*p]=false;

                if(i%p==0) break;
            }
        }
        int count=0;
        for(int i=2;i<n;i++)
        {
            if(isPrime[i]) count++;
        }
        return count;
    }
};