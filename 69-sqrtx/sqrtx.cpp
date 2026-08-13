class Solution {
public:
    int mySqrt(int x) {
        int low=0;
        int high=x;
        int res=x;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            long long prod=1LL*mid*mid;
            if(prod<=x)
            {
                res=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return res;
    }
};