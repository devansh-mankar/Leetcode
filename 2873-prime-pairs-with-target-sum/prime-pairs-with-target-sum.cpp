class Solution {
public:
    
    vector<int>solve(int n)
    {
        vector<int>ans;
       vector<bool>isPrime(n+1,true);
       isPrime[0]=0,isPrime[0]=0;

       for(int i=2;i<=sqrt(n);i++)
       {
            if(isPrime[i])
            {
                for(int j=i*i;j<=n;j=j+i)
                {
                    isPrime[j]=false;
                }
            }
       }

        for(int i=2;i<=n;i++)
        {
            if(isPrime[i])
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
    vector<vector<int>> findPrimePairs(int n) {
        vector<int>primes=solve(n);
        vector<vector<int>>ans;
        int size=primes.size();
        
        int i=0,j=size-1;
        while(i<=j)
        {
            int sum=primes[i]+primes[j];
            if(sum==n)
            {
                ans.push_back({primes[i],primes[j]});
                i++,j--;
            }
            else if(sum>n)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return ans;
    }
};