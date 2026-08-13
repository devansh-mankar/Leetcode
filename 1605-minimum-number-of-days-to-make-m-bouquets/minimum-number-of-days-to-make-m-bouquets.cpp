class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();

        if(((long long)m*k)>n) return -1;

        int low=0;
        int high=*max_element(bloomDay.begin(),bloomDay.end());

        while(low<high)
        {
            int mid=low+(high-low)/2;
            long long bouq=0,count=0;

            for(int i=0;i<n;i++)
            {
                if(bloomDay[i]<=mid)
                {
                    count++;
                    if(count==k)
                    {
                        bouq++;
                        count=0;
                    }
                }
                else{
                    count=0;
                }
            }
            if(bouq>=m)
            {
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};