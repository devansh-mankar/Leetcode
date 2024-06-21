class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>&board)
    {
        if(row<0 || row>=board.size() || col<0 || col>=board[0].size() || vis[row][col] || board[row][col]!='O')
        {
            return;
        }
        
        vis[row][col]=true;
        dfs(row+1,col,vis,board);
        dfs(row-1,col,vis,board);
        dfs(row,col+1,vis,board);
        dfs(row,col-1,vis,board);
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