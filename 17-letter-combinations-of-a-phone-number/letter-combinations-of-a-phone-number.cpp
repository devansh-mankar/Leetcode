class Solution {
public:
    void solve(int index,int n,string& temp,vector<string>&ans,vector<string>&num,string& digits)
    {
        if(index==n)
        {
            ans.push_back(temp);
            return;
        }
        int value=digits[index]-'0';
        string s=num[value];

        for(int i=0;i<s.size();i++)
        {
            temp.push_back(s[i]);
            solve(index+1,n,temp,ans,num,digits);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        string temp="";
        int n=digits.size();
        vector<string>num={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(0,n,temp,ans,num,digits);
        return ans;
    }
};