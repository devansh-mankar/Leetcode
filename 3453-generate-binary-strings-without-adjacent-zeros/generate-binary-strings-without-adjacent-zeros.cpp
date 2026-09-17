class Solution {
public:
    void solve(int n,string& curr,vector<string>&res)
    {
        if(curr.size()==n)
        {
            res.push_back(curr);
            return;
        }
        curr.push_back('1');
        solve(n,curr,res);
        curr.pop_back();

        if(curr.empty() || curr.back()!='0')
        {
            curr.push_back('0');
            solve(n,curr,res);
            curr.pop_back();
        }
        
    }
    vector<string> validStrings(int n) {
        vector<string>res;
        string curr="";
        solve(n,curr,res);
        return res;
    }
};