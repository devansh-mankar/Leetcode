class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0,right=0,maxlen=0;
        int length=0,count=0;
        int n=nums.size();
        while(right<n)
        {
            if(nums[right]==0)
            {
                count++;
            }
            while(count>k)
            {
                if(nums[left]==0)
                {
                    count--;
                }
                left++;
            }
            if(count<=k)
            {
                length=right-left+1;
                maxlen=max(length,maxlen);
            }
            right++;
        }
        return maxlen;
    }
};