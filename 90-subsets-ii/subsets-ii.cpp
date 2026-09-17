class Solution {
public:
    void solve(int index,int n,vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans)
    {
        ans.push_back(temp);
        for(int i=index;i<n;i++)
        {
            if(i>index && nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            solve(i+1,n,nums,temp,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>temp;
        solve(0,nums.size(),nums,temp,ans);
        return ans;
    }
};