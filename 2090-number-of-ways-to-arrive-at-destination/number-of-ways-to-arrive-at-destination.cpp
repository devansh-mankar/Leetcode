class Solution {
public:
    int mod=(int)1000000007;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>>adj[n];

        for(auto it:roads)
        {
            int u=it[0];
            int v=it[1];
            int wt=it[2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;

        vector<long long>dist(n,1e15);
        vector<int>ways(n,0);
        dist[0]=0;
        ways[0]=1;

        pq.push({0,0});

        while(!pq.empty())
        {
            int node=pq.top().second;
            long long distance=pq.top().first;
            pq.pop();

            for(auto it:adj[node])
            {
                if(it.second+distance<dist[it.first])
                {
                    dist[it.first]=it.second+distance;
                    pq.push({dist[it.first],it.first});
                    ways[it.first]=ways[node];
                }
                else if(distance+it.second==dist[it.first])
                {
                    ways[it.first]=(ways[node]+ways[it.first])%mod;
                }

            }
        }
        return ways[n-1]%mod;
    }
};