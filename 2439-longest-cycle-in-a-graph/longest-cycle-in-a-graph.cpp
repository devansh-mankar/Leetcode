class Solution {
public:
    int result=-1;
    void dfs(int node,vector<int>&vis,vector<int>&dfsCall,vector<int>&count,vector<int>&edges)
    {
        if(node!=-1)
        {
            vis[node]=true;
            dfsCall[node]=true;

            int it=edges[node];
            if(it!=-1 && !vis[it])
            {
                count[it]=count[node]+1;
                dfs(it,vis,dfsCall,count,edges);
            }
            else if(it!=-1 && dfsCall[it])
            {
                result=max(result,count[node]-count[it]+1);

            }
            dfsCall[node]=false;
        }
    }
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<int>vis(n,0);
        vector<int>dfsCall(n,0);
        vector<int>count(n,1);

        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,dfsCall,count,edges);
            }
        }
        return result;
    }
};