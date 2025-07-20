class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);

        for(auto it:flights)
        {
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
        }

        vector<vector<int>>dist(n,vector<int>(k+2,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{src,0}});
        dist[src][0]=0;

        while(!pq.empty())
        {
            int distance=pq.top().first;
            int stops=pq.top().second.second;
            int node=pq.top().second.first;
            pq.pop();

             if(node==dst)
            {
                return distance;
            }

            if(stops>k)
            {
                continue;
            }
            if(distance>dist[node][stops])
            {
                continue;
            }
           

            for(auto it:adj[node])
            {
                if(stops+1<=k+1 && it.second+distance<dist[it.first][stops+1])
                {
                    dist[it.first][stops+1]=it.second+distance;
                    pq.push({dist[it.first][stops+1],{it.first,stops+1}});
                }
            }
        }
        return -1;
    }
};