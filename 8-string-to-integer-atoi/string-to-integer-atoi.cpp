class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        int i=0;
        long ans=0;
        bool negative=false;

        while(i<n && s[i]==' ')
        {
            i++;
        }
        if(i<n && (s[i]=='+' || s[i]=='-'))
        {
            negative=(s[i]=='-');
            i++;
        }
        while(i<n && (s[i]>='0' && s[i]<='9'))
        {
            ans=ans*10+(s[i]-'0');
            if(ans>INT_MAX)
            {
                return negative?INT_MIN:INT_MAX;
            }
            i++;
        }
        return negative?-ans:ans;
    }
};