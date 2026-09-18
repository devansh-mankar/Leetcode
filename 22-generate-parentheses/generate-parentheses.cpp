class Solution {
public:
    void solve(int open,int close,int n,string curr,vector<string>&res)
    {
        if(curr.size()==2*n)
        {
            res.push_back(curr);
            return;
        }
        if(open<n) solve(open+1,close,n,curr+'(',res);
        if(close<open) solve(open,close+1,n,curr+')',res);
    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        string curr="";
        solve(0,0,n,curr,res);
        return res;
    }
};