class Solution {
public:
    bool dfs(int node,vector<int>&vis,stack<int>&s,vector<vector<int>>&adj,vector<int>&dfsCall)
    {
        vis[node]=true;
        dfsCall[node]=true;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                if(dfs(it,vis,s,adj,dfsCall))
                {
                    return true;
                }
            }
            if(dfsCall[it])
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
        stack<int>s;
        vector<int>dfsCall(numCourses,0);
        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,s,adj,dfsCall);
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