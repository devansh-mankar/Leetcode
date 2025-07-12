class Solution {
public:
    void bfs(int node,vector<vector<int>>&adj,vector<int>&vis)
    {
        vis[node]=true;
        queue<int>q;
        q.push(node);

        while(!q.empty())
        {
            int front=q.front();
            q.pop();

            for(auto it:adj[front])
            {
                if(!vis[it])
                {
                    vis[it]=true;
                    q.push(it);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>>adj(n);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j && isConnected[i][j]==1)
                {
                    adj[i].push_back(j);
                }
            }
        }


        vector<int>vis(n,0);
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                count++;
                bfs(i,adj,vis);
            }
        }
        return count;
    }
};