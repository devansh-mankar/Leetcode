class DisjointSet{
    vector<int>parent,rank,size;
    public:
    DisjointSet(int n)
    {
        parent.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
        }
    }

    int findUPar(int node)
    {
        if(node==parent[node])
        {
            return node;
        }
        return parent[node]=findUPar(parent[node]);
    }

    void unionByRank(int u,int v)
    {
        int pu=findUPar(u);
        int pv=findUPar(v);
        if(pu==pv)
        {
            return;
        }
        if(rank[pu]<rank[pv])
        {
            parent[pu]=pv;
        }
        else if(rank[pv]<rank[pu])
        {
            parent[pv]=pu;
        }
        else{
            parent[pu]=pv;
            rank[pv]++;
        }
    }

    void unionBySize(int u,int v)
    {
        int pu=findUPar(u);
        int pv=findUPar(v);
        if(pu==pv)
        {
            return;
        }
        if(size[pu]<size[pv])
        {
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else{
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }

    bool connected(int u,int v)
    {
        return findUPar(u)==findUPar(v);
    }
};
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();

        vector<tuple<int,int,int>>edges;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int cell=i*m+j;

                if(j+1<m)
                {
                    int weight=abs(heights[i][j+1]-heights[i][j]);
                    edges.push_back({weight,cell,cell+1});
                }
                if(i+1<n)
                {
                    int weight=abs(heights[i+1][j]-heights[i][j]);
                    edges.push_back({weight,cell,cell+m});
                }
            }
        }
        sort(edges.begin(),edges.end());
        DisjointSet ds(n*m);

        for(auto [weight,u,v]:edges)
        {
            ds.unionByRank(u,v);
            if(ds.connected(0,n*m-1))
            {
                return weight;
            }
        }
        return 0;
    }
};