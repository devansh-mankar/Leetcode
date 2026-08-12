class Solution {
public:
    int findFirst(vector<int>&nums,int target)
    {
        int low=0;
        int high=nums.size()-1;
        int res=-1;

        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
            {
                res=mid;
                high=mid-1;
            }
            else if(nums[mid]>target)
            {
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return res;
    }
    int findLast(vector<int>&nums,int target)
    {
        int low=0;
        int high=nums.size()-1;

        int res=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
            {
                res=mid;
                low=mid+1;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int first=findFirst(nums,target);
        int last=findLast(nums,target);

        if(first==-1)
        {
            return {-1,-1};
        }
        return {first,last};
    }
};