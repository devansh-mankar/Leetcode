class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];

        for(auto it:flights)
        {
            int u=it[0];
            int v=it[1];
            int wt=it[2];

            adj[u].push_back({v,wt});
        }

        queue<pair<int,pair<int,int>>>q;
        q.push({0,{0,src}});

        vector<int>dist(n,INT_MAX);

        while(!q.empty())
        {
            int stops=q.front().first;
            int node=q.front().second.second;
            int distance=q.front().second.first;
            q.pop();

            if(stops>k)
            {
                continue;
            }

            for(auto it:adj[node])
            {
                if(distance+it.second<dist[it.first])
                {
                    dist[it.first]=it.second+distance;
                    q.push({stops+1,{dist[it.first],it.first}});
                }
            }
        }

        if(dist[dst]==INT_MAX)
        {
            return -1;
        }
        return dist[dst];
    }
};