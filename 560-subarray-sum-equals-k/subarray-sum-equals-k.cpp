class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        map<int,int>mp;
        int sum=0;
        mp[0]++;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            int rem=sum-k;
            if(mp.find(rem)!=mp.end())
            {
                count+=mp[rem];
            }   
            mp[sum]++;
        }
        return count;
    }
};