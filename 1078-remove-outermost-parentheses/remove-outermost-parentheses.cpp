class Solution {
public:
    string removeOuterParentheses(string s) {
        int depth=0;
        string res="";
        for(auto it:s)
        {
            if(it=='(')
            {
                depth++;
                //now check if it is inner parantheses or not
                if(depth>1) res+=it;
            }
            else{
                if(depth>1) res+=it;
                depth--;
            }
        }
        return res;
    }
};