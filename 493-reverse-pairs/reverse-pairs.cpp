class Solution {
public:
    int merge(vector<int>&nums,int low,int mid,int high)
    {
        int left=low;
        int right=mid+1;

        int count=0;
        for(int i=low;i<=mid;i++)
        {
            while(right<=high && nums[i]>2LL*nums[right])
            {
                right++;
            }
            count+=(right-(mid+1));
        }

        right=mid+1;
        vector<int>temp;

        while(left<=mid && right<=high)
        {
            if(nums[left]<=nums[right])
            {
                temp.push_back(nums[left++]);
            }
            else{
                temp.push_back(nums[right++]);
            }
        }

        while(left<=mid)
        {
            temp.push_back(nums[left++]);
        }

        while(right<=high)
        {
            temp.push_back(nums[right++]);
        }

        for(int i=low;i<=high;i++)
        {
            nums[i]=temp[i-low];
        }

        return count;
    }
    int mergeSort(vector<int>&nums,int low,int high)
    {
        if(low>=high)
        {
            return 0;
        }
        int count=0;
        int mid=low+(high-low)/2;
        count+=mergeSort(nums,low,mid);
        count+=mergeSort(nums,mid+1,high);
        count+=merge(nums,low,mid,high);

        return count;
    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        return mergeSort(nums,0,n-1);
    }
};