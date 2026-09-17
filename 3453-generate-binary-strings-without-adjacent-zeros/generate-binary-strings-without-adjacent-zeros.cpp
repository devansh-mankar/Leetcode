class Solution {
public:
    void solve(int n,string curr,vector<string>&res)
    {
        if(curr.size()==n)
        {
            res.push_back(curr);
            return;
        }

        solve(n,curr+'1',res);

        if(curr.empty() || curr.back()!='0')
        {
            solve(n,curr+'0',res);
        }
    }
    vector<string> validStrings(int n) {
        vector<string>res;
        string curr="";
         solve(n,curr,res);
         return res;
    }
};