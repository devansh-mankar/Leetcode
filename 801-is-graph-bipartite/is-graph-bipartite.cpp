class Solution {
public:
    bool bfs(int node,vector<int>&color,vector<vector<int>>&graph)
    {
        queue<int>q;
        q.push(node);
        color[node]=0;

        while(!q.empty())
        {
            int front=q.front();
            q.pop();

            for(auto it:graph[front])
            {
                if(color[it]==-1)
                {
                    q.push(it);
                    color[it]=!color[front];
                }
                else if(color[it]==color[front])
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                if(!bfs(i,color,graph))
                {
                    return false;
                }
            }
        }
        return true;
    }
};