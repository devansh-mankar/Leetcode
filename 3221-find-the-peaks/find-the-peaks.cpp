class Solution {
public:
    vector<int> findPeaks(vector<int>& mountain) {
        vector<int>ans;
        int n=mountain.size()-1;
        for(int i=1;i<n;i++)
        {
            if(mountain[i-1]<mountain[i] && mountain[i]>mountain[i+1])
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};