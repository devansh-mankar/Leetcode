class Solution {
public:
    long solve(int i,string& s,bool negative,long ans)
    {
        if(ans>INT_MAX)
        {
            return negative?INT_MIN:INT_MAX;
        }
        if(i>=s.size() || s[i]<'0' || s[i]>'9')
        {
            return negative?-ans:ans;
        }
        return solve(i+1,s,negative,ans*10+s[i]-'0');
    }
    int myAtoi(string s) {
        int i=0;
        
        int n=s.size();
        bool negative=false;

        while(i<n && s[i]==' ')
        {
            i++;
        }
        if(i<n && (s[i]=='-' || s[i]=='+'))
        {
            negative=(s[i]=='-');
            i++;
        }
        return solve(i,s,negative,0);
    }
};