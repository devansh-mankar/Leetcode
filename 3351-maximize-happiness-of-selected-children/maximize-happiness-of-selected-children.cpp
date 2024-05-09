class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans=0;
        sort(happiness.begin(),happiness.end());
        int size=happiness.size()-1;
        int count=0;
        
        while(k>0 && size>=0)
        {
            ans=ans+max(0,happiness[size]-count);
            count++;
            k--;
            size--;
        }
        return ans;
    }
};