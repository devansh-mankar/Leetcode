class Solution {
public:
    bool dfs(int node,stack<int>&s,vector<int>&vis,vector<int>&dfsCall,vector<vector<int>>&adj)
    {
        vis[node]=true;
        dfsCall[node]=true;
       

        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                if(dfs(it,s,vis,dfsCall,adj))
                {
                    return true;
                }
            }
            else if(dfsCall[it])
            {
                return true;
            }
        }
         s.push(node);
        dfsCall[node]=false;
        return false;
        
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);

        for(int i=0;i<prerequisites.size();i++)
        {
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];

            adj[v].push_back(u);
        }

        vector<int>vis(numCourses,0);
        vector<int>dfsCall(numCourses,0);
        stack<int>s;

        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
            {
                dfs(i,s,vis,dfsCall,adj);
            }
        }

        vector<int>ans;
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }

        if(ans.size()!=numCourses)
        {
            return {};
        }
        return ans;

    }
};