class Solution {
public:
    vector<int> getRow(int rowIndex) {
        long long prev=1;
        vector<int>ans;
        ans.push_back(1);

        for(int i=1;i<=rowIndex;i++)
        {
            long long next=prev*(rowIndex-i+1)/i;
            ans.push_back(next);
            prev=next;
        }
        return ans;
    }
};