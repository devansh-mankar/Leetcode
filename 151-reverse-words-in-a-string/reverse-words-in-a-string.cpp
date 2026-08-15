class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        vector<string>temp;
        string str="";

        int i=0;

        while(i<n)
        {
            while(i<n && s[i]==' ')
            {
                i++;
            }
            while(i<n && s[i]!=' ')
            {
                str+=s[i++];
            }
            if(str!="")
            {
                temp.push_back(str);
                str="";
            }
        }

        string ans="";
        for(int i=temp.size()-1;i>=0;i--)
        {
            ans+=temp[i];
            if(i!=0)
            {
                ans+=" ";
            }
        }
        return ans;
    }
};