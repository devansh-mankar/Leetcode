class Solution {
public:
    bool dfs(int row,int col,int effort,vector<vector<int>>&heights,vector<vector<int>>&vis)
    {
        if(row==heights.size()-1 && col==heights[0].size()-1)
        {
            return true;
        }
        vis[row][col]=true;
        vector<int>dr={-1,0,1,0};
        vector<int>dc={0,1,0,-1};

        for(int i=0;i<4;i++)
        {
            int nr=row+dr[i];
            int nc=col+dc[i];
            if(nr>=0 && nr<heights.size() && nc>=0 && nc<heights[0].size() && !vis[nr][nc])
            {
                int neff=abs(heights[nr][nc]-heights[row][col]);
                if(neff<=effort && dfs(nr,nc,effort,heights,vis))
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool canReach(int effort,vector<vector<int>>&heights)
    {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        return dfs(0,0,effort,heights,vis);
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int left=0,right=1000000;

        while(left<right)
        {
            int mid=left+(right-left)/2;

            if(canReach(mid,heights))
            {
                right=mid;
            }
            else{
                left=mid+1;
            }
        }
        return left;
    }
};