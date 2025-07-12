class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty()) return;

        int n=board.size();
        int m=board[0].size();

        queue<pair<int,int>>q;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || i==n-1 || j==0 || j==m-1)
                {
                    if(board[i][j]=='O')
                    {
                         board[i][j]='P';
                    q.push({i,j});
                    }
                   
                }
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