class Solution {
public:
    void solve(int index,int n,vector<int>&temp,vector<vector<int>>&ans,vector<int>&nums)
    {
        ans.push_back(temp);

        for(int i=index;i<n;i++)
        {
            if(i>index && nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            solve(i+1,n,temp,ans,nums);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(nums.begin(),nums.end());
        solve(0,nums.size(),temp,ans,nums);
        return ans;
    }
};