class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        int index=1,maxi=1;
        if(n==0)
        {
            return 0;
        }

        for(int i=0;i<n-1;i++)
        {
            if(abs(nums[i+1]-nums[i])==1)
            {
                index++;
                maxi=max(index,maxi);
            }
            else if(abs(nums[i+1]-nums[i])==0)
            {
                continue;
            }
            else
            {
                index=1;
            }
        }
        return maxi;
    }
};