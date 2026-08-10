class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();

        vector<int>temp;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                temp.push_back(grid[i][j]);
            }
        }

        int repeating=-1;
        int missing=-1;

        for(int i=1;i<=n*n;i++)
        {
            int count=0;
            for(int j=0;j<n*n;j++)
            {
                if(i==temp[j])
                {
                    count++;
                }
            }
            if(count==2)
            {
                repeating=i;
            }
            else if(count==0)
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