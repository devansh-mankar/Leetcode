class Solution {
public:
    void solve(int index,int n,vector<string>&num,string& digits,string temp,vector<string>&ans)
    {
        if(index==n)
        {
            ans.push_back(temp);
            return;
        }
        int number=digits[index]-'0';
        string value=num[number];

        for(int i=0;i<value.size();i++)
        {
            temp.push_back(value[i]);
            solve(index+1,n,num,digits,temp,ans);
            temp.pop_back();
        }
        
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        string temp="";

        vector<string>num={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int n=digits.size();
        solve(0,n,num,digits,temp,ans);
        return ans;
    }
};