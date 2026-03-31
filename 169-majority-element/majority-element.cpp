class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();

        int count=0;
        int ele=0;

        for(int i=0;i<n;i++)
        {
            if(count==0)
            {
                count=1;
                ele=nums[i];
            }
            else if(ele==nums[i])
            {
                count++;
            }
            else{
                count--;
            }
        }

        //checking
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==ele)
            {
                cnt++;
            }
        }
        if(cnt>(n/2))
        {
            return ele;
        }
        return -1;
    }
};