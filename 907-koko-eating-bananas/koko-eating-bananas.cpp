class Solution {
public:
   
    long long calc(vector<int>&piles,int hourly)
    {
        long long totalH=0;
        for(int i=0;i<piles.size();i++)
        {
            totalH+=ceil(piles[i]*1.0/hourly);
        }
        return totalH;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
         sort(piles.begin(),piles.end());
        int low=1,high=piles[n-1];
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            long long  reqTime=calc(piles,mid);
            if(reqTime<=h)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return (int)low;
    }
};