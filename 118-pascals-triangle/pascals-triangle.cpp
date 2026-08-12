class Solution {
public:
    vector<int>solve(int n)
    {
        long long prev=1;
        vector<int>temp;
        temp.push_back(1);

        for(int i=1;i<=n;i++)
        {
            long long next=prev*(n-i+1);
            next/=i;
            temp.push_back(next);
            prev=next;
        }
        return temp;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        ans.push_back({1});
        for(int i=1;i<numRows;i++)
        {
            ans.push_back(solve(i));
        }
        return ans;
    }
};