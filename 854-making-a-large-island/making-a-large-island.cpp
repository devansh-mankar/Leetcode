class Disjointset{
    public:
    vector<int>rank,parent,size;

    Disjointset(int n)
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

    void UnionBySize(int u,int v)
    {
        int pu=findUPar(u);
        int pv=findUPar(v);

        if(pu==pv)
        {
            return;
        }
        if(size[pu]<size[pv])
        {
            size[pv]+=size[pu];
            parent[pu]=pv;
        }
        else
        {
            size[pu]+=size[pv];
            parent[pv]=pu;
        }
    }

    void UnionByRank(int u,int v)
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
        else
        {
            parent[pv]=pu;
            rank[pv]++;
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int ans=0;

        Disjointset ds(n*n);

        vector<int>dr={-1,0,1,0};
        vector<int>dc={0,1,0,-1};

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
            
                if(grid[i][j]==0)
                {
                    continue;
                }
                for(int k=0;k<4;k++)
                {
                    int nr=i+dr[k];
                    int nc=j+dc[k];

                    if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1)
                    {
                        int node=i*n+j;
                        int adjnode=nr*n+nc;

                        ds.UnionBySize(node,adjnode);
                    }
                }
            }
        }  


        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    continue;
                }
                unordered_set<int>s;
                for(int k=0;k<4;k++)
                {
                    int nr=i+dr[k];
                    int nc=j+dc[k];

                    if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1)
                    {
                       
                        int adjnode=nr*n+nc;

                        s.insert(ds.findUPar(adjnode));
                    }
                }
                int ts=0;
                for(auto it:s)
                {
                    ts+=ds.size[it];
                }
                ans=max(ts+1,ans);
            }

        }

        for(int cellno=0;cellno<n*n;cellno++)
        {
            ans=max(ans,ds.size[ds.findUPar(cellno)]);
        }
        return ans;
    }
};