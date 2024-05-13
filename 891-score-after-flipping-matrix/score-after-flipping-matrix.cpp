class Solution {
public:
    void flipCol(int col , vector<vector<int>> &grid , int n)
    {
        for(int row = 0 ; row < n ; row++)
        {
            grid[row][col]=!grid[row][col];
        }
    }
    void flipRow(int row , vector<vector<int>> &grid , int m)
    {
        for(int col = 0 ; col < m ; col++)
        {
            grid[row][col]=!grid[row][col];
        }
    }

    int value(vector<int> &temp)
    {
        int n = temp.size();
        int val = 1;
        int ans = 0;

        for(int i = n-1 ; i >= 0 ; i--)
        { 
            ans += (temp[i] * val);
            val = (val << 1);
        }

        return ans;
    }

    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for(int row = 0 ; row < n ; row++)
        {
            if(grid[row][0] == 0)
            {
                flipRow(row , grid , m);
            }
        }

        for(int col = 0 ; col < m ; col++)
        {
            int cntOne = 0;
            for(int row = 0 ; row < n ; row++)
            {
                if(grid[row][col] == 1)cntOne++;
            }
            if(cntOne <= n/2)
            {
                flipCol(col , grid , n);
            }
        }

        int ans = 0;

        for(int i = 0 ; i < n ; i++)
        {
            ans += value(grid[i]);
        }

        return ans;
    }
};