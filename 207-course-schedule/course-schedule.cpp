class Solution {
public:
    bool dfs(int node,vector<int>&vis,vector<int>&dfsCall,vector<int>adj[])
    {
        vis[node]=1;
        dfsCall[node]=1;

        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                if(dfs(it,vis,dfsCall,adj))
                {
                    return true;
                }
                
            }
            else if(dfsCall[it])
                {
                    return true;
                }
        }
        dfsCall[node]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];

        for(auto it:prerequisites)
        {
            int u=it[0];
            int v=it[1];

            adj[u].push_back(v);
        }

        vector<int>vis(numCourses,0);
        vector<int>dfsCall(numCourses,0);
        
        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,vis,dfsCall,adj))
                {
                    return false;
                }
            }
        }
        return true;
    }
};