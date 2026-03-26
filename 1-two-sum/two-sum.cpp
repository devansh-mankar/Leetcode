class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();

        unordered_map<int,int>mp;

        for(int i=0;i<n;i++)
        {
            int num=nums[i];
            int rem=target-num;

            if(mp.find(rem)!=mp.end())
            {
                return {mp[rem],i};
            }
            mp[num]=i;
        }
        return {-1,-1};
    }
};