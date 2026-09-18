class Solution {
public:
    void solve(int index,int n,int k,vector<int>&temp,vector<vector<int>>&ans)
    {
        if(temp.size()==n)
        {
            if(k==0)
            {
                ans.push_back(temp);
            }
              return;
        }
        
        if(k<0) return;

        for(int i=index;i<=9;i++)
        {
            temp.push_back(i);
            solve(i+1,n,k-i,temp,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(1,k,n,temp,ans);
        return ans;
    }
};