class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>matrix(n,vector<int>(n,INT_MAX));

        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            int wt=it[2];

            matrix[u][v]=wt;
            matrix[v][u]=wt;
        }

        for(int i=0;i<n;i++)
        {
            matrix[i][i]=0;
        }


        for(int via=0;via<n;via++)
        {
            for(int i=0;i<n;i++)
            {
                if(via==i)
                {
                    continue;
                }
                for(int j=0;j<n;j++)
                {
                    if(via==j)
                    {
                        continue;
                    }
                    else
                    {
                        if(matrix[i][via]==INT_MAX || matrix[via][j]==INT_MAX)
                        {
                            continue;
                        }
                        matrix[i][j]=min(matrix[i][j],matrix[i][via]+matrix[via][j]);
                    }
                }
            }
        }



        int cityNo=-1;
        int countCity=n;

        for(int i=0;i<n;i++)
        {
            int count=0;
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]<=distanceThreshold)
                {
                    count++;
                }
            }
            if(count<=countCity)
            {
                countCity=count;
                cityNo=i;
            }
        }

        return cityNo;
    }
};