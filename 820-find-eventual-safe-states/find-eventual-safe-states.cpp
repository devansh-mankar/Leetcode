class Solution {
public:
    bool dfs(int node,vector<int>&vis,vector<int>&dfsCall,vector<vector<int>>&graph,vector<int>&check)
    {
        dfsCall[node]=true;
        vis[node]=true;

        for(auto it:graph[node])
        {
            if(!vis[it])
            {
                if(dfs(it,vis,dfsCall,graph,check))
                {
                    return true;
                }
            }
            else if(dfsCall[it])
            {
                return true;
            }
        }
        check[node]=true;
        dfsCall[node]=false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();

        vector<int>ans;
        vector<int>vis(n,0);
        vector<int>dfsCall(n,0);
        vector<int>check(n,0);

        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,dfsCall,graph,check);
            }
        }

        for(int i=0;i<n;i++)
        {
            if(check[i]==1)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};