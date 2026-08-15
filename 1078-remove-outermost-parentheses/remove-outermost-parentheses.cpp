class Solution {
public:
    string removeOuterParentheses(string s) {
        int depth=0;
        string str="";

        for(auto it:s)
        {
            if(it=='(')
            {
                depth++;
                if(depth>1) str+=it;
            }
            else{
                if(depth>1) str+=it;
                depth--;
            }
        }
        return str;
    }
};