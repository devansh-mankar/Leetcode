class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();

        unordered_map<int,int>mp;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                mp[grid[i][j]]++;
            }
        }

        int repeating=-1;
        int missing=-1;

        for(int i=1;i<=n*n;i++)
        {
            if(mp[i]==2)
            {
                repeating=i;
            }
            else if(mp[i]==0)
            {
                missing=i;
            }
            if(repeating!=-1 && missing!=-1)
            {
                return {repeating,missing};
            }
        }

        return {-1,-1};
    }
};