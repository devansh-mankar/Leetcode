class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;
        int ans=0;
        for(auto it:s)
        {
            if(it=='(')
            {
                st.push(it);
            }
            else if(it==')')
            {
                st.pop();
            }
            else
            {
                continue;
            }
            ans=max(ans,(int)st.size());
        }
        return ans;
    }
};