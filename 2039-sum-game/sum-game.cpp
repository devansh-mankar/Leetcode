class Solution {
public:
    bool sumGame(string num) {
        int n=num.size();

        int lsum=0;
        int rsum=0;

        int leftQ=0;
        int rightQ=0;

        for(int i=0;i<n/2;i++)
        {
            if(num[i]=='?') leftQ++;
            else lsum+=(num[i]-'0');
        }

        for(int i=n/2;i<n;i++)
        {
            if(num[i]=='?') rightQ++;
            else rsum+=(num[i]-'0');
        }

        return ((lsum-rsum)*2)!=(rightQ-leftQ)*9;
    }
};