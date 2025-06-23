class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<int>st;
        string ans="";

        for(auto it:s)
        {
            if(it=='(')
            {
                if(!st.empty())
                {
                    //it means we are not at outermost
                    ans+=it;
                }
                st.push(it);
            }
            else{
                st.pop();
                if(!st.empty())
                {
                    ans+=it;
                }
            }
        }
        return ans;

    }
};