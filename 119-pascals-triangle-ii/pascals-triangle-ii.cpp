class Solution {
public:
    int solve(int n,int r)
    {
        long long res=1;
        for(int i=0;i<r;i++)
        {
            res=res*(n-i);
            res/=(i+1);
        }
        return res;
    }
    vector<int> getRow(int rowIndex) {
        vector<int>ans;

        for(int i=0;i<=rowIndex;i++)
        {
            ans.push_back(solve(rowIndex,i));
        }
        return ans;
    }
};