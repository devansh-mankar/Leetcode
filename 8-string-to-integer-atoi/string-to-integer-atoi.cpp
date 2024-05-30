class Solution {
public:
    long solve(string &s,int sign,int i,long result)
    {
        if((sign*result)>=INT_MAX)
        {
            return INT_MAX;
        }
        if((sign*result)<=INT_MIN)
        {
            return INT_MIN;
        }
        if(i>=s.length() || s[i]<'0' || s[i]>'9')
        {
            return sign*result;
        }
        return solve(s,sign,i+1,(result*10+s[i]-'0'));
    
    }
    int myAtoi(string s) {
        int n=s.size();
        int i=0;
        int sign=1;

       
        
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
        return solve(s,sign,i,0);
        
    }
};