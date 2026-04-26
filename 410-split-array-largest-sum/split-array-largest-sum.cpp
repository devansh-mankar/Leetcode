class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();

        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        int res=1;

        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int count=1;
            long long sum=0;
            for(int i=0;i<n;i++)
            {
                if(sum+nums[i]>mid)
                {
                    count++;
                    sum=nums[i];
                }
                else{
                    sum+=nums[i];
                }
                if(count>k) break;
            }
            if(count<=k)
            {
                res=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return res;
    }
};