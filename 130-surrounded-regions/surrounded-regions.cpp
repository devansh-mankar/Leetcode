class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>&board)
    {
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        vis[row][col]=true;

        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<4;i++)
        {  
            int nrow=row+dr[i];
            int ncol=col+dc[i];

        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && board[nrow][ncol]=='O')
        {
            dfs(nrow,ncol,vis,board);
        }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || i==n-1 || j==0 || j==m-1)
                {
                    if(board[i][j]=='O')
                    {
                        dfs(i,j,vis,board);
                    }
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && board[i][j]=='O')
                {
                    board[i][j]='X';
                }
            }
        }
    }
};