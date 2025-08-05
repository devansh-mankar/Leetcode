class Solution {
public:
    void dfs(int current,int distance,vector<int>&dist,vector<int>&edges)
    {
        while(current!=-1 && dist[current]==-1)
        {
            dist[current]=distance++;
            current=edges[current];
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int res=-1;
        int min_of_max=INT_MAX;
        int n=edges.size();

        vector<int>dist1(n,-1);
        vector<int>dist2(n,-1);

        dfs(node1,0,dist1,edges);
        dfs(node2,0,dist2,edges);

        for(int i=0;i<n;i++)
        {
            if(dist1[i]>=0 && dist2[i]>=0)
            {
                int maxi=max(dist1[i],dist2[i]);
                if(maxi<min_of_max)
                {
                    min_of_max=maxi;
                    res=i;
                }
            }
        }
        return res;
    }
};