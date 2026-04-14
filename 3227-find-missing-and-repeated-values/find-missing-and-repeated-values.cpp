class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();

        vector<int>hash(n*n+1,0);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                hash[grid[i][j]]++;
            }
        }
        int repeating=-1;
        int missing=-1;
        for(int i=1;i<=n*n;i++)
        {
            if(hash[i]==2)
            {
                repeating=i;
            }
            else if(hash[i]==0)
            {
                missing=i;
            }

            if(repeating!=-1 && missing!=-1)
            {
                break;
            }
        }
        return {repeating,missing};
    }
};