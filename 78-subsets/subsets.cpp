class Solution {
public:
    void solve(int index,int n,vector<int>&temp,vector<vector<int>>&ans,vector<int>&nums)
    {
        if(index==n)
        {
            ans.push_back(temp);
            return;
        }
        solve(index+1,n,temp,ans,nums);
        temp.push_back(nums[index]);
        solve(index+1,n,temp,ans,nums);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(0,nums.size(),temp,ans,nums);
        return ans;
    }
};