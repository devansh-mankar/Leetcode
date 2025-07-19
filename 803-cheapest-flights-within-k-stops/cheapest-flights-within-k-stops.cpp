class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);

        for(int i=0;i<flights.size();i++)
        {
            int u=flights[i][0];
            int v=flights[i][1];
            int wt=flights[i][2];
            adj[u].push_back({v,wt});
        }

        vector<int>dist(n,INT_MAX);
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        dist[src]=0;

        while(!q.empty())
        {
            int stops=q.front().first;
            int node=q.front().second.first;
            int distance=q.front().second.second;
            q.pop();

            if(stops>k)
            {
                continue;
            }
            for(auto it:adj[node])
            {
                if(it.second+distance<dist[it.first])
                {
                    dist[it.first]=it.second+distance;
                    q.push({stops+1,{it.first,dist[it.first]}});
                }
            }
        }

        return dist[dst]==INT_MAX?-1:dist[dst];
    }
};