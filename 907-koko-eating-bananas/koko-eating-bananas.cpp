class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();

        int low=0;
        int high=*max_element(piles.begin(),piles.end());
        int res=0;

        while(low<=high)
        {
            int mid=low+(high-low)/2;
            double count=0;
            for(int i=0;i<n;i++)
            {
                count+=ceil(((double)piles[i]/(double)mid));
            }
            if(count<=h)
            {
                res=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return res;
    }
};