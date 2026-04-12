class Solution {
public:
    int CrossSumCalc(vector<int>&nums,int left,int mid,int right)
    {
        int sum=0;
        int lsum=INT_MIN;

        for(int i=mid;i>=left;i--)
        {
            sum+=nums[i];
            lsum=max(lsum,sum);
        }

        sum=0;
        int rsum=INT_MIN;
        for(int i=mid+1;i<=right;i++)
        {
            sum+=nums[i];
            rsum=max(rsum,sum);
        }

        return lsum+rsum;
    }
    int maxSubarrayDandQ(vector<int>&nums,int left,int right)
    {
        if(left==right)
        {
            return nums[left];
        }
        int mid=left+(right-left)/2;
        int leftMax=maxSubarrayDandQ(nums,left,mid);
        int rightMax=maxSubarrayDandQ(nums,mid+1,right);
        int crossSum=CrossSumCalc(nums,left,mid,right);

        return max({leftMax,rightMax,crossSum});
    }
    int maxSubArray(vector<int>& nums) {
        return maxSubarrayDandQ(nums,0,nums.size()-1);
    }
};