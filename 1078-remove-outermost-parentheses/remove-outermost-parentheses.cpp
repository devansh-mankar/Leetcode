class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<int>st;

        string res="";

        for(auto it:s)
        {
            if(it=='(')
            {
                if(!st.empty())
                {
                    res+=it;
                }
                st.push(it);
            }
            else{
                st.pop();
                if(!st.empty()) res+=it;
            }
        }
        return res;
    }
};