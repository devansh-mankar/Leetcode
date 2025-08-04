class Solution {
public:
    bool rabin_karp(string text,string pattern)
    {
        long long h=1;
        int n=text.size();
        int m=pattern.size();

        const int base=256;
        const int mod=1e9+7;

        for(int i=0;i<m-1;i++)
        {
            h=(h*base)%mod;
        }

        long long p_hash=0;
        long long t_hash=0;

        for(int i=0;i<m;i++)
        {   
            p_hash=(p_hash*base+pattern[i])%mod;
            t_hash=(t_hash*base+text[i])%mod;
        }


        for(int i=0;i<=n-m;i++)
        {
            if(p_hash==t_hash)
            {
                if(text.substr(i,m)==pattern)
                {
                    return true;
                }
            }

            if(i<n-m)
            {
                t_hash=(t_hash-text[i]*h)%mod;
                t_hash=(t_hash*base+text[i+m])%mod;

                if(t_hash<0) t_hash+=mod;
            }
        }
        return false;
    }
    int repeatedStringMatch(string a, string b) {
        if(a==b)
        {
            return 1;
        }
        int count=1;
        string source=a;
        while(source.size() < b.size())
        {
            count++;
            source+=a;
        }

        if(source==b) return count;
        if(rabin_karp(source,b)) return count;

        if(rabin_karp(source+a,b)) return count+1;

        return -1;

    }
};