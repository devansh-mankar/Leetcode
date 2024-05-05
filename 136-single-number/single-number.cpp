class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(auto it:nums)
        {
            ans=ans^it;
        }
        return ans;
    }
};