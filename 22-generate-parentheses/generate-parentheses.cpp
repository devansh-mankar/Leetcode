class Solution {
public:
    void solve(int n,int open,int close,string curr,vector<string>&res)
    {
        if(curr.size()==2*n)
        {
            res.push_back(curr);
            return;
        }
        if(open<n) solve(n,open+1,close,curr+'(',res);
        if(close<open) solve(n,open,close+1,curr+')',res);
    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        string curr="";
        solve(n,0,0,curr,res);
        return res;
    }
};