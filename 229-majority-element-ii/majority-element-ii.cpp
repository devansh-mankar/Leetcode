class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();

        vector<int>ans;

        for(int i=0;i<n;i++)
        {
            int count=0;
            for(int j=0;j<n;j++)
            {
                if(nums[i]==nums[j])
                {
                    count++;
                }
            }
            if(count>(n/3))
            {
                if(find(ans.begin(),ans.end(),nums[i])==ans.end())
                {
                    ans.push_back(nums[i]);
                }
            }
        }

        return ans;
    }
};