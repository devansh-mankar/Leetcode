class Solution {
public:
    bool isValid(string s) {
        stack<char>st;

        for(auto c:s)
        {
            if(c=='(' || c=='{' || c=='[')
            {
                st.push(c);
            }
            else{
                if(!st.empty())
                {
                  char  top=st.top();
                    if((c==')' && top=='(') || (c==']' && top=='[') || (c=='}' && top=='{'))
                    {
                        st.pop();
                    }
                    else return false;
                }
                else return false;
            }
        }

        return st.empty();
    }
};