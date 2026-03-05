class Solution {
public:
    bool checkRow(int row,vector<vector<int>>&mat)
    {
        int count=0;
        for(int i=0;i<mat[0].size();i++)
        {
            if(mat[row][i]) count++;
            if(count>1) return false;
        }

        return count==1;
    }
    bool checkCol(int col,vector<vector<int>>&mat)
    {
        int count=0;

        for(int i=0;i<mat.size();i++)
        {
            if(mat[i][col]) count++;
            if(count>1) return false;
        }
        return count==1;
    }
    int numSpecial(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        int count=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==1)
                {
                    if(checkRow(i,mat) && checkCol(j,mat))
                    {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};