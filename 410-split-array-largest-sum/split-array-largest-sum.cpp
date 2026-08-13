class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();

        long long low=*max_element(nums.begin(),nums.end());
        long long high=accumulate(nums.begin(),nums.end(),0);

        while(low<high)
        {
            int mid=low+(high-low)/2;
            long long sum=0;
            int count=1;
            for(int i=0;i<n;i++)
            {
                if(sum+nums[i]>mid)
                {
                    sum=nums[i];
                    count++;
                }
                else{
                    sum+=nums[i];
                }
                if(count>k) break;
            }
            if(count<=k)
            {
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};