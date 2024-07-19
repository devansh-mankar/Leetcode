class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        vector<int>ans;

        for(int i=0;i<n;i++)
        {
            int mini=INT_MAX;
            int index=-1;

            for(int j=0;j<m;j++)
            {
                if(mini>matrix[i][j])
                {
                    mini=matrix[i][j];
                    index=j;
                }
            }
            int maxi=INT_MIN;
            for(int j=0;j<n;j++)
            {
                if(maxi<matrix[j][index])
                {
                    maxi=matrix[j][index];
                }
            }
            if(mini==maxi)
            {
                ans.push_back(mini);
            }
        }
        return ans;
    }
};