class Solution {
public:
    void solve(int index,int n,vector<int>&nums,int target,vector<int>&temp,vector<vector<int>>&ans)
    {
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }
        if(index==n || nums[index]>target) return;

        for(int i=index;i<n;i++)
        {
            if(i>index && nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            solve(i+1,n,nums,target-nums[i],temp,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>temp;
        solve(0,candidates.size(),candidates,target,temp,ans);
        return ans;
    }
};