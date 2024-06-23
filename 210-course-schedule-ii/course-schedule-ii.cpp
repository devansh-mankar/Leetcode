class Solution {
public:
    bool dfs(int node,vector<int>&vis,vector<int>adj[],stack<int>&s,vector<int>&dfsCall)
    {
        vis[node]=true;
        dfsCall[node]=true;

        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                if(dfs(it,vis,adj,s,dfsCall))
                {
                    return true;
                }
                
            }
            else if(dfsCall[it])
            {
                return false;
            }
        }
        s.push(node);
        dfsCall[node]=false;
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];

        for(auto it:prerequisites)
        {
            int u=it[0];
            int v=it[1];

            adj[v].push_back(u);
        }

        vector<int>vis(numCourses,0);
          vector<int>dfsCall(numCourses,0);
        stack<int>s;

        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,adj,s,dfsCall);
            }
        }

        vector<int>ans;
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        if(ans.size()==numCourses)
        {
            return ans;
        }
        return vector<int>();
    }
};