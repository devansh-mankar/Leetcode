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

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>dist(n,vector<int>(k+2,INT_MAX));

        pq.push({0,{src,0}});
        dist[src][0]=0;

        while(!pq.empty())
        {
            auto top=pq.top();
            int distance=top.first;
            int node=top.second.first;
            int stops=top.second.second;
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
                if(stops+1<=k+1 && dist[it.first][stops+1]>distance+it.second)
                {
                    dist[it.first][stops+1]=distance+it.second;
                    pq.push({dist[it.first][stops+1],{it.first,stops+1}});
                }
            }
        }
        return -1;
    }
};