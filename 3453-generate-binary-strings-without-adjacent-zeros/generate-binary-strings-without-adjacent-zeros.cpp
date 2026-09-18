class Solution {
public:
    void solve(int index,int n,string& curr,vector<string>&res)
    {
        if(index==n)
        {
            res.push_back(curr);
            return;
        }

        curr.push_back('1');
        solve(index+1,n,curr,res);
        curr.pop_back();

        if(curr.empty() || curr.back()!='0')
        {
            curr.push_back('0');
            solve(index+1,n,curr,res);
            curr.pop_back();
        }
    }
    vector<string> validStrings(int n) {
        vector<string>res;
        string curr="";
        solve(0,n,curr,res);
        return res;
    }
};