class Solution {
public:
    void solve(int index,int n,vector<int>&nums,int target,vector<int>&temp,vector<vector<int>>&ans)
    {
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }
        if(target<0) return;

        for(int i=index;i<n;i++)
        {
            temp.push_back(nums[i]);
            solve(i,n,nums,target-nums[i],temp,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        int n=candidates.size();
        solve(0,n,candidates,target,temp,ans);
        return ans;
    }
};