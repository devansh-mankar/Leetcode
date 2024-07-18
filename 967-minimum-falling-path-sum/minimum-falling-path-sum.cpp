class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();

        vector<vector<int>>dp(n,vector<int>(n,0));

        for(int i=0;i<n;i++)
        {
            dp[0][i]=matrix[0][i];
        }


        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int up=matrix[i][j]+dp[i-1][j];

                int ld=matrix[i][j];
                if(j>0)
                {
                    ld+=dp[i-1][j-1];
                }
                else
                {
                    ld+=1e9;
                }
                int rd=matrix[i][j];
                if(j+1<matrix.size())
                {
                    rd+=dp[i-1][j+1];
                }
                else
                {
                    rd+=1e9;
                }
                dp[i][j]=min({up,ld,rd});
            }

        }
        int mini=INT_MAX;
        for(int i=0;i<n;i++)
        {
            mini=min(mini,dp[n-1][i]);
        }
        return mini;
    }
};