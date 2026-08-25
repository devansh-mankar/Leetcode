class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();
        int num=1;
        int multiple=k;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            if(multiple==nums[i])
            {
                num++;
                multiple=k*num;   
            }
        }
        return multiple;
    }
};