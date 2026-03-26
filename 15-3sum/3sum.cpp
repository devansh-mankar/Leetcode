class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;

        for(int i=0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;
            int left=i+1;
            int right=n-1;
            while(left<right)
            {
                long long sum=nums[left]+nums[right]+nums[i];
                if(sum==0)
                {
                    ans.push_back({nums[i],nums[left++],nums[right--]});
                    while(left<right && nums[left]==nums[left-1]) left++;
                    while(left<right && nums[right]==nums[right+1]) right--;
                }

                else if(sum>0)
                {
                    right--;
                }
                else{
                    left++;
                }
            }
        }
        return ans;
    }
};