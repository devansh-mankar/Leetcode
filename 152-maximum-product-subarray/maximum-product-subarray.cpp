class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int result=nums[0];
        for(int i=0;i<n;i++)
        {
            int p=nums[i];
            for(int j=i+1;j<n;j++)
            {
                result=max(p,result);
                p=p*nums[j];
            }
            //for n-1 term
             result=max(p,result);
        }
        return result;
    }
};