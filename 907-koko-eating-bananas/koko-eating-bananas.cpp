class Solution {
public:
    long long calc(vector<int>&piles,int mid)
    {
        long long hours=0;
        for(int i=0;i<piles.size();i++)
        {
            hours+=(ceil)((double)piles[i]/(double)mid);
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();

        int maxi=*max_element(piles.begin(),piles.end());
        long long low=1;
        long long high=maxi;

        while(low<=high)
        {
            long long mid=low+(high-low)/2;
            long long val=calc(piles,mid);

            if(val<=h)
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