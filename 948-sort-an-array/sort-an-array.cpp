class Solution {
public:
    int partition(vector<int>&nums,int low,int high)
    {
        int i=low-1;
        int j=high+1;

        int pivot=nums[low];

        while(1)
        {
            do{
                i++;
            }while(nums[i]<pivot);

            do{
                j--;
            }while(nums[j]>pivot);

            if(i>=j) return j;

            swap(nums[i],nums[j]);
        }
    }
    void HoareQuickSort(vector<int>&nums,int low,int high)
    {
        if(low>=high) return;

        int part=partition(nums,low,high);
        HoareQuickSort(nums,low,part);
        HoareQuickSort(nums,part+1,high);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();

        HoareQuickSort(nums,0,n-1);

        return nums;
    }
};