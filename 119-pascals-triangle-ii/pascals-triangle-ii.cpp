class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>ans;
        long long prev=1;
        ans.push_back(1);

        for(int i=1;i<=rowIndex;i++)
        {
            long long next=prev*(rowIndex-i+1);
            next/=i;
            ans.push_back(next);
            prev=next;
        }
        return ans;
    }
};