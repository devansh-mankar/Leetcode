class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();

        string temp="";

        for(int i=0;i<n;i++)
        {
            if((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9'))
            {
                temp+=s[i];
            }
            else if(s[i]>='A' && s[i]<='Z'){
                temp+=(s[i]+32);
            }
        }

        int i=0,j=temp.size()-1;

        while(i<=j)
        {
            if(temp[i++]!=temp[j--])
            {
                return false;
            }
        }
        return true;
    }
};