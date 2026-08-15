class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        stack<string>st;

        int i=0;
        while(i<n)
        {
            while(i<n && s[i]==' ')
            {
                i++;
            }
            string str="";
            while(i<n && s[i]!=' ')
            {
                str+=s[i++];
            }
            if(!str.empty())
            {
                st.push(str);
            }
        }

        string ans="";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
            if(!st.empty())
            {
                ans+=" ";
            }
        }
        return ans;
    }
};