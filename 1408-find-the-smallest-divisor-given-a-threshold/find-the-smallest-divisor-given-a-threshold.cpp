class Solution {
public:
    long long calc(vector<int>&nums,int div)
    {
        long long sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=ceil(1.0*nums[i]/div);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
     int n=nums.size();
      int maxi=*max_element(nums.begin(),nums.end());

      
      int low=1,high=maxi;
      while(low<=high)
      {
        int mid=low+(high-low)/2;
        long long sum=calc(nums,mid);
        if(sum<=threshold)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
      }
      return low;

    }
};