class Solution {
public:
    bool isValid(string& s)
    {
        int count=0;
        for(auto c:s)
        {
            if(c=='(')
            {
                count++;
            }
            if(c==')')
            {
                count--;
            }
            if(count<0) return false;
        }
        return count==0;
    }
    void solve(int n,string curr,vector<string>&res)
    {
        if(2*n==curr.size())
        {
            if(isValid(curr))
            {
                res.push_back(curr);
            }
            return;
        }

        solve(n,curr+'(',res);
        solve(n,curr+')',res);
    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        string curr="";
        solve(n,curr,res);
        return res;
    }
};