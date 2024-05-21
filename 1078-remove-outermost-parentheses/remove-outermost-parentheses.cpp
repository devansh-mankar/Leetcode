class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int depth=0;

        for(auto it:s)
        {
            if(it=='(')
            {
                depth++;
            }
            if(depth!=1)
            {
                ans.push_back(it);
            }
             if(it==')')
            {
                depth--;
            }
        }
        return ans;
    }
};