class Solution {
public:
    void solve(int index,int n,string& digits,vector<string>&num,string& temp,vector<string>&ans)
    {
        if(index==n)
        {
            ans.push_back(temp);
            return;
        }

        int val=digits[index]-'0';
        string s=num[val];

        for(int i=0;i<s.size();i++)
        {
            temp.push_back(s[i]);
            solve(index+1,n,digits,num,temp,ans);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        string temp="";
        vector<string>num={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int n=digits.size();
        solve(0,n,digits,num,temp,ans);
        return ans;
    }
};