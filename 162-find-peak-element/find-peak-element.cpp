class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int n=nums.size();
        if(nums.size()==1)
        {
            return 0;
        }
        else if(nums[0]>nums[1])
        return 0;
        else if(nums[n-1]>nums[n-2])
        return n-1;
        else
        {
        int start=1,end=n-2,mid;

    while(start<=end)
    {
      mid=start+(end-start)/2;
      if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
      return mid;
      else if(nums[mid+1]>nums[mid])
      {
        start=mid+1;
      }
      else
      {
        end=mid-1;
      }
    }
        return -1;
    }

    }
};