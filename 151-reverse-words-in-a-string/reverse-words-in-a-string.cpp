class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        int i=0;
        string temp="";
        string ans="";


        while(i<n)
        {
            if(i<n && s[i]==' ')
            {
                i++;
            }
            temp="";
            while(i<n && s[i]!=' ')
            {
                temp+=s[i++];
            }
            if(!temp.empty())
            {
                if(!ans.empty())
                {
                    ans=temp+" "+ans;
                }
                else{
                    ans=temp;
                }
            }
        }

        return ans;
    }
};