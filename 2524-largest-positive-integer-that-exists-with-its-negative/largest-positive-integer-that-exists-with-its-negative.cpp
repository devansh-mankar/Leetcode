class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int>s(nums.begin(),nums.end());
        int pair=-1;

        for(auto it:nums)
        {
            if(it>0 && s.count(-it))
            {
                pair=max(pair,it);
            }
        }
        return pair;
    }
};