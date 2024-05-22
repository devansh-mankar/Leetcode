class Solution {
public:
    int myAtoi(string s) {
       
        long result=0;
        int sign=1;
        int i=0;
            while(i<s.length() && s[i]==' ')
            {
                i++;
            }
            if(s[i]=='-')
            {
                sign=-1;
                i++;
            }
            else if(s[i]=='+')
            {
                i++;
            }
           while(i<s.length())
           {
            if(s[i]>='0' && s[i]<='9')
            {
                result=result*10+(s[i]-'0');
                if(result>INT_MAX && sign==-1)
                {
                    return INT_MIN;
                }
                else if(result>INT_MAX && sign==1)
                {
                    return INT_MAX;
                }
                i++;
            }
            else
            {
                return result*sign;
            }
           }
        
        return (result*sign);
    }
};