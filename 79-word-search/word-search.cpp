class Solution {
public:
    bool check(int i,int j,int index,string word,vector<vector<char>>&board,vector<vector<int>>&vis)
    {
        if(index==word.size()) return true;

        int n=board.size();
        int m=board[0].size();

        vector<int>dr={-1,0,1,0};
        vector<int>dc={0,1,0,-1};

        for(int k=0;k<4;k++)
        {
            int nr=i+dr[k];
            int nc=j+dc[k];
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && board[nr][nc]==word[index])
            {
                vis[nr][nc]=1;
                if(check(nr,nc,index+1,word,board,vis))
                {
                    return true;
                }
                vis[nr][nc]=0;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0])
                {
                    vis[i][j]=1;
                    if(check(i,j,1,word,board,vis))
                    {
                        return true;
                    }
                    vis[i][j]=0;
                } 
            }
        }
        return false;
    }
};