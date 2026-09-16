class Solution {
public:
    long long solve(int index,string& s,bool& sign,long long res)
    {
        if(index>=s.size())
        {
            return sign ? -res:res;
        }
       
        if(s[index]>='0' && s[index]<='9')
        {

             if((res*10+(s[index]-'0'))>INT_MAX)
            {
                return sign ? INT_MIN:INT_MAX;
            }
            return solve(index+1,s,sign,res*10+(s[index]-'0'));
        }
        return sign ? -res:res;
    }
    int myAtoi(string s) {
        int n=s.size();

        int i=0;
        while(i<n && s[i]==' ') i++;

        long long res=0;
        bool sign=0;

        if(s[i]=='-' || s[i]=='+')
        {
            sign = (s[i]=='-') ? 1:0;
            i++;
        }
        return (int)solve(i,s,sign,res);
    }
};