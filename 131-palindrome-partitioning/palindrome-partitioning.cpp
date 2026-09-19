class Solution {
public:
    bool valid(string& s,int i,int j)
    {
        while(i<=j)
        {
            if(s[i++]!=s[j--])
            {
                return false;
            }
        }
        return true;
    }   
    void solve(int index,int n,string& s,vector<string>&temp,vector<vector<string>>&ans)
    {
        if(index==n)
        {
            ans.push_back(temp);
            return;
        }

        for(int i=index;i<s.size();i++)
        {
            if(valid(s,index,i)){
                temp.push_back(s.substr(index,i-index+1));
                solve(i+1,n,s,temp,ans);
                temp.pop_back();
            }
        }

        

    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        int n=s.size();
        //string str="";
        solve(0,n,s,temp,ans);
        return ans;
    }
};