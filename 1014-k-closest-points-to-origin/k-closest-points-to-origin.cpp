class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        priority_queue<pair<int,pair<int,int>>>pq;
        int n=points.size();

        for(int i=0;i<n;i++)
        {
            pq.push({points[i][0]*points[i][0]+points[i][1]*points[i][1],{points[i][0],points[i][1]}});
            if(pq.size()>k)
            {
                pq.pop();
            }
        }

        while(!pq.empty())
        {
            pair<int,int>p=pq.top().second;
            vector<int>point={p.first,p.second};
            ans.push_back(point);
            pq.pop();
        }
        return ans;

    }
};