class Solution {
public:
    int findDays(vector<int>&weights,int cap)
    {
        int count=1;
        int load=0;
        for(int i=0;i<weights.size();i++)
        {
            if(load+weights[i]>cap)
            {
                count++;
                load=weights[i];
                
            }
            else
            {
                load+=weights[i];
            }
        }
        return count;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int maxi=*max_element(weights.begin(),weights.end());
        int sum=accumulate(weights.begin(),weights.end(),0);

       int low=maxi,high=sum;
       while(low<=high)
       {
        int mid=low+(high-low)/2;
        if(findDays(weights,mid)<=days)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
       }
       return low;
    }
};