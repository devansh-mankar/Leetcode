class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        bool sign=0;
        long long num=0;

        int i=0;
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
            num=num*10+(s[i]-'0');
            if(num>INT_MAX)
            {
                return sign ? INT_MIN:INT_MAX;
            }
            i++;
        }
        return sign ? -num:num;
    }
};