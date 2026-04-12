class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();

        sort(nums.begin(),nums.end());

        int index=1;
        int maxi=1;

        if(n==0)
        {
            return 0;
        }

        for(int i=0;i<n-1;i++)
        {
            if(abs(nums[i]-nums[i+1])==1)
            {
                index++;
                maxi=max(maxi,index);
            }
            else if(abs(nums[i]-nums[i+1])==0)
            {
                continue;
            }
            else{
                index=1;
            }
        }

        return maxi;
    }
};