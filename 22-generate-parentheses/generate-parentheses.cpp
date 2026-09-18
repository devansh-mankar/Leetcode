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
            if(count<0) return 0;
        }
        return count==0;
    }
    void solve(int index,int n,string curr,vector<string>&res)
    {
        if(index==2*n)
        {
            if(isValid(curr))
            {
                res.push_back(curr);
            }
            return;
        }
        
        solve(index+1,n,curr+'(',res);
        solve(index+1,n,curr+')',res);
    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        string curr="";
        solve(0,n,curr,res);
        return res;
    }
};