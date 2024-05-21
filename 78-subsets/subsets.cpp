class Solution {
public:
    vector<vector<int>>ans;
    vector<int>output;

    void backtracking(vector<int>&nums,int index)
    {
        ans.push_back(output);
        if(index>=nums.size())
        {
            return;
        }

        for(int i=index;i<nums.size();i++)
        {
            output.push_back(nums[i]);
            backtracking(nums,i+1);
            output.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums,0);
        return ans;
    }
};