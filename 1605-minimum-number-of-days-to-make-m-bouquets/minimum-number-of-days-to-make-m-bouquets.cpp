class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();

        int maxi=*max_element(bloomDay.begin(),bloomDay.end());

        if(n<(long long)m*k)
        {
            return -1;
        }

        int low=1;
        int high=maxi;

        while(low<=high)
        {
            int mid=low+(high-low)/2;

            int bouquets=0;
            int count=0;
            for(int i=0;i<n;i++)
            {
                if(mid>=bloomDay[i])
                {
                    count++;
                    if(count==k)
                    {
                        bouquets++;
                        count=0;
                    }
                }
                else{
                    count=0;
                }
            }

            if(bouquets>=m)
            {
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};