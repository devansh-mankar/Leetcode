class Solution {
public:
    int maxDepth(string s) {
        int n=s.size();
        stack<char>st;
        int maxi=-1;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                st.push(s[i]);
            }
            maxi=max(maxi,(int)st.size());
            if(s[i]==')')
            {
                st.pop();
            }
        }
        return maxi;
        
    }
};