class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mp;
        int n=nums.size();
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