class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        int i=0;

        while(i<n && s[i]==' ') i++;

        bool sign=0;
        if(s[i]=='-' || s[i]=='+')
        {
            sign= (s[i]=='-' ? 1:0);
            i++;
        }

        long long res=0;

        while(i<n && (s[i]>='0' && s[i]<='9'))
        {
            if(res*10+(s[i]-'0')>INT_MAX) return sign ? INT_MIN:INT_MAX;

            res=res*10+(s[i]-'0');
            i++;
        }
        return sign ? -res:res;
    }
};