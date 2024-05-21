class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        string temp="";
        string ans="";
        vector<string>v;

        for(int i=0;i<n;i++)
        {
            if(s[i]==' ')
            {
                temp="";
            }
            while(i<s.length() && s[i]!=' ')
            {
                temp+=s[i++];
            }
            if(temp!="")
            {
                v.push_back(temp);
                temp="";
            }
        }

        for(int i=v.size()-1;i>=0;i--)
        {
            ans+=v[i];
            if(i!=0)
            {
                ans+=" ";
            }
        }
        return ans;
    }
};