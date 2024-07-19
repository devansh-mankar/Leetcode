class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        
        vector<int>prev(n,0);
        vector<int>curr(n,0);

        for(int i=0;i<n;i++)
        {
            prev[i]=matrix[0][i];
        }   

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int up=matrix[i][j]+prev[j];

                int ld=matrix[i][j];

                if(j>0)
                {
                    ld+=prev[j-1];
                }
                else
                {
                    ld+=1e9;
                }
                int rd=matrix[i][j];
                if(j+1<n)
                {
                    rd+=prev[j+1];
                }else{
                    rd+=1e9;
                }

                curr[j]=min({up,ld,rd});

            }
            prev=curr;
        }

        int mini=INT_MAX;
        for(int i=0;i<n;i++)
        {
            mini=min(mini,prev[i]);
        }
        return mini;
    }
};