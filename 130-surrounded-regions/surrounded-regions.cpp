class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty()) return;
        int n=board.size();
        int m=board[0].size();

        queue<pair<int,int>>q;

        for(int i=0;i<n;i++)
        {
            if(board[i][0]=='O')
            {
                board[i][0]='P';
                q.push({i,0});
            }
            if(board[i][m-1]=='O')
            {
                board[i][m-1]='P';
                q.push({i,m-1});
            }
        }

        for(int j=0;j<m;j++)
        {
            if(board[0][j]=='O')
            {
                q.push({0,j});
                board[0][j]='P';
            }
            if(board[n-1][j]=='O')
            {
                q.push({n-1,j});
                board[n-1][j]='P';
            }
        }


        vector<int>dr={-1,0,1,0};
        vector<int>dc={0,1,0,-1};
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            for(int i=0;i<4;i++)
            {
                    int nr=row+dr[i];
                    int nc=col+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && board[nr][nc]=='O')
                {
                    board[nr][nc]='P';
                    q.push({nr,nc});
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O')
                {
                    board[i][j]='X';
                }
                else if(board[i][j]=='P')
                {
                    board[i][j]='O';
                }
            }
        }

    }
};