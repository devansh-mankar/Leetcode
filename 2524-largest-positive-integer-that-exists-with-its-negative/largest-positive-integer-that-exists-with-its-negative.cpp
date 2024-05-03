class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int ans=0;
        int i=0,j=nums.size()-1;
        while(i<=j)
        {
            int sum=nums[i]+nums[j];
            if(sum==0)
            {
                return nums[j];
            }
            else if(sum>0)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return -1;
    }
};