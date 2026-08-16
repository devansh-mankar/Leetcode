class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        bool sign=false;
        long ans=0;

        int n=s.size();

        while(i<n && s[i]==' ')
        {
            i++;
        }
        if(i<n && (s[i]=='-' || s[i]=='+'))
        {
            sign=(s[i]=='-');
            i++;
        }
        while(i<n && (s[i]>='0' && s[i]<='9'))
        {
            ans=ans*10+(s[i]-'0');
            if(ans>INT_MAX)
            {
                return sign? INT_MIN:INT_MAX;
            }
            i++;
        }
        return sign? -ans:ans;
    }
};