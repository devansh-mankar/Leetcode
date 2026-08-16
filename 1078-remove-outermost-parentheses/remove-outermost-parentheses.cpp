class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.size();
        string ans="";
        int depth=0;

        for(auto it:s)
        {
            if(it=='(')
            {
                depth++;
                if(depth>1)
                {
                    ans+=it;
                }
                
              
            }
            else{
                if(depth>1)
                ans+=it;
                depth--;
            }
        }
        return ans;
    }
};