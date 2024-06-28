class Solution {
public:
    vector<int>parent;
    int findUPar(int node,vector<int>&parent)
    {
        if(node==parent[node])
        {
            return node;
        }
        return node=findUPar(parent[node],parent);
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)
        {
            return -1;
        }
        vector<int>parent(n);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }

        for(auto it:connections)
        {
            int u=it[0];
            int v=it[1];

            int pu=findUPar(u,parent);
            int pv=findUPar(v,parent);

            if(pu!=pv)
            {
                parent[pu]=pv;
            }
            
        }

        int count=-1;
        for(int i=0;i<n;i++)
        {
            if(parent[i]==i)
            {
                count++;
            }
        }
        return count;
    }
};