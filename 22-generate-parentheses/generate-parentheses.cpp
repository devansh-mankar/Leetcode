class Solution {
public:
    void solve(int n,int open,int close,string curr,vector<string>& res)
    {
        if(n*2==curr.size())
        {
            res.push_back(curr);
            return;
        }
        if(open<n) solve(n,open+1,close,curr+'(',res);
        if(close<open) solve(n,open,close+1,curr+')',res);
    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        int open=0;
        int close=0;
        string curr="";
        solve(n,open,close,curr,res);
        return res;
    }
};