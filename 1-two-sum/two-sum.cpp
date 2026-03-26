class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        int i=0,j=1;

        while(i<n-1 && j<n)
        {
            if(nums[i]+nums[j]==target)
            {
                return {i,j};
            }
            else if(j==n-1)
            {
                i++;
                j=i;
            }
            j++;
        }
        return {-1,-1};
    }
};