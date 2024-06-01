class Solution {
public:
    bool isSafe(int row,int col,int n,vector<string>&board)
    {
        int x=row;
        int y=col;

        while(y>=0)
        {
            if(board[x][y]=='Q')
            {
                return false;
            }
            y--;
        }
        x=row;
        y=col;
        while(x>=0 && y>=0)
        {
            if(board[x][y]=='Q')
            {
                return false;
            }
            x--;
            y--;
        }
        x=row;
        y=col;
        while(x<n && y>=0)
        {
            if(board[x][y]=='Q')
            {
                return false;
            }
            x++;
            y--;
        }
        return true;

    }
    void solve(int col,int n,vector<string>&board,vector<vector<string>>&ans)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }

        for(int row=0;row<n;row++)
        {
            if(isSafe(row,col,n,board))
            {
                board[row][col]='Q';
                solve(col+1,n,board,ans);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n,string(n,'.'));
        solve(0,n,board,ans);
        return ans;
    }
};