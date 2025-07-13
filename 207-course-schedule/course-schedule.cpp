class Solution {
public:
    bool dfs(int node,vector<int>&vis,vector<int>&dfsCall,vector<vector<int>>&adj)
    {
        vis[node]=true;
        dfsCall[node]=true;

        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                if(dfs(it,vis,dfsCall,adj))
                {
                    return true;
                }
            }
            if(dfsCall[it])
            {
                return true;
            }
        }
        dfsCall[node]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);

        for(int i=0;i<prerequisites.size();i++)
        {
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
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