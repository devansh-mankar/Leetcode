class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.size(),n2=s2.size(),n3=s3.size();
        if(n3!=n1+n2)
        {
            return 0;
        }

        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));

        for(int i=n1;i>=0;i--)
        {
            for(int j=n2;j>=0;j--)
            {
                int k=i+j;
                if(i==n1 && j==n2)
                {
                    dp[i][j]=1;
                }
                else if(s3[k]==s1[i] && s3[k]==s2[j])
                {
                    dp[i][j]=dp[i+1][j] || dp[i][j+1];
                }
                else if(s3[k]==s1[i])
                {
                    dp[i][j]=dp[i+1][j];
                }
                else if(s3[k]==s2[j])
                {
                    dp[i][j]=dp[i][j+1];
                }
                else{
                    dp[i][j]=false;
                }
            }
        }
        return dp[0][0];
    }
};