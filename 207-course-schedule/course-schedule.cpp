class Solution {
public:
   
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];

        for(auto it:prerequisites)
        {
            int u=it[0];
            int v=it[1];

            adj[u].push_back(v);
        }

        vector<int>indegree(numCourses,0);
        for(int i=0;i<numCourses;i++)
        {
            for(auto it:adj[i])
            {
                indegree[it]++;
            }
        }

        queue<int>q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }

        int count=0;
        while(!q.empty())
        {
            int front=q.front();
            q.pop();
            count++;

            for(auto it:adj[front])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q.push(it);
                }
            }
        }

        if(count==numCourses)
        {
            return true;
        }
        return false;
        
    }
};