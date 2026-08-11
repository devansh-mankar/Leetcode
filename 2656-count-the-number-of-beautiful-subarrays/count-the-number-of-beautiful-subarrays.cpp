class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        int n=nums.size();

        long long count=0;
        unordered_map<int,long long>mp;
        long long xorr=0;
        mp[0]=1;
        for(int i=0;i<n;i++)
        {
            xorr=xorr^nums[i];
            if(mp.find(xorr)!=mp.end())
            {
                count+=mp[xorr];
            }
            mp[xorr]++;
        }
        return count;
    }
};