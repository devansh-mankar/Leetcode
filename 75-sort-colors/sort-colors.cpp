class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();

        int zero=0;
        int one=0;
        int two=0;

        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                zero++;
            }
            else if(nums[i]==1)
            {
                one++;
            }
            else{
                two++;
            }
        }


        for(int i=0;i<zero;i++)
        {
            nums[i]=0;
        }
        for(int i=zero;i<one+zero;i++)
        {
            nums[i]=1;
        }
        for(int i=one+zero;i<n;i++)
        {
            nums[i]=2;
        }
    }
};