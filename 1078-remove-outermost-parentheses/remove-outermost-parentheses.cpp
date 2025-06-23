class Solution {
public:
    string removeOuterParentheses(string s) {
        int depth=0;
        string ans="";

        for(auto it:s)
        {
            if(it=='(')
            {
                depth++;
            }
            if(depth!=1)
            {
                ans+=it;
            }
            if(it==')')
            {
                depth--;
            }
        }
        return ans;
    }
};