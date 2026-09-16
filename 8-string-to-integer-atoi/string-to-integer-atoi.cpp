class Solution {
public:
    long long solve(int i,string& s,bool& sign,long long res)
    {
        if(i>=s.size())
        {
            return sign ? -res:res;
        }
        if(s[i]>='0' && s[i]<='9')
        {
            if(res*10+(s[i]-'0')>INT_MAX) return sign ? INT_MIN:INT_MAX;

            return solve(i+1,s,sign,res*10+(s[i]-'0'));
        }
        return sign ? -res:res;
    }
    int myAtoi(string s) {
        int n=s.size();
        int i=0;

        while(i<n && s[i]==' ') i++;

        bool sign=0;
        if(s[i]=='-' || s[i]=='+')
        {
            sign = (s[i]=='-' ? 1:0);
            i++;
        }
        long long res=0;
        return solve(i,s,sign,res);

    }
};