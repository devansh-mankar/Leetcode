class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);

        for(auto it:times)
        {
            int u=it[0];
            int v=it[1];
            int wt=it[2];

            adj[u].push_back({v,wt});
        }

        vector<int>dist(n+1,INT_MAX);

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        dist[k]=0;

        while(!pq.empty())
        {
            int node=pq.top().second;
            int distance=pq.top().first;
            pq.pop();

            if(distance>dist[node])
            {
                continue;
            }
            for(auto it:adj[node])
            {
                if(it.second+distance<dist[it.first])
                {
                    dist[it.first]=it.second+distance;
                    pq.push({dist[it.first],it.first});
                }
            }
        }

        int mx=0;
        for(int i=1;i<=n;i++)
        {
            if(dist[i]==INT_MAX)
            {
                return -1;
            }
            mx=max(mx,dist[i]);
        }
        return mx;
    }
};