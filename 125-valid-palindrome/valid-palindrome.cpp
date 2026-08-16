class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        string str="";

        for(int i=0;i<n;i++)
        {
            if(s[i]>='A' && s[i]<='Z')
            {
                str+=(s[i]+32);
            }
            if((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9'))
            {
                str+=s[i];
            }
        }

        int i=0;
        int j=str.size()-1;
        while(i<=j)
        {
            if(str[i++]!=str[j--])
            {
                return false;
            }
        }
        return true;
    }
};