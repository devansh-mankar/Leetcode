class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp(n,0);

        int index=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=0)
            {
                temp[index++]=nums[i];
            }
        }
        nums=temp;
    }
};