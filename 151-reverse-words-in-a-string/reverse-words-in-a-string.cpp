class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        int n=s.size();
        string temp="";
        string ans="";

        for(int i=0;i<n;i++)
        {
            if(s[i]==' ')
            {
                if(!temp.empty())
                {
                    st.push(temp);
                    temp="";
                }
                
            }
            else{
                    temp+=s[i];
                }
        }

        if(!temp.empty())
        {
            st.push(temp);
        }


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