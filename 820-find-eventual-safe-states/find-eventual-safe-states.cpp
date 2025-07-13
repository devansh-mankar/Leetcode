class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //already graph is the adjacency list
        int n=graph.size();
        vector<int>indegree(n,0);
        vector<vector<int>>adj(n);

        for(int i=0;i<n;i++)
        {
            for(auto j:graph[i])
            {
                adj[j].push_back(i);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(auto it:adj[i])
            {
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        vector<int>ans;
        int count=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            ans.push_back(node);

            for(auto it:adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q.push(it);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};