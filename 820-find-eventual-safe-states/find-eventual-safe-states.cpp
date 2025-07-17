class Solution {
public:
    bool dfs(int node,vector<int>&vis,vector<int>&dfsCall,vector<int>&ans,vector<vector<int>>&graph)
    {
        vis[node]=true;
        dfsCall[node]=true;
        for(auto it:graph[node])
        {
            if(!vis[it])
            {
                if(dfs(it,vis,dfsCall,ans,graph))
                {
                    return true;
                }
                
            }
            if(dfsCall[it])
            {
                return true;
            }

        }
        ans.push_back(node);
        dfsCall[node]=false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,0);
        vector<int>dfsCall(n,0);
        vector<int>ans;

        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,dfsCall,ans,graph);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};