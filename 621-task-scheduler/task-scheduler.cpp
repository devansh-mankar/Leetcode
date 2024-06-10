class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;

        for(auto it:tasks)
        {
            mp[it]++;
        }
        priority_queue<int>pq;

        for(auto it:mp)
        {
            pq.push(it.second);
        }


        int time=0;
        while(!pq.empty())
        {
            vector<int>temp;
            for(int i=1;i<=n+1;i++)
            {
                if(!pq.empty())
                {
                    int freq=pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }
            for(auto i:temp)
            {
                if(i>0)
                {
                    pq.push(i);
                }
            }

            if(pq.empty())
            {
                time+=temp.size();
            }
            else
            {
                time+=n+1;
            }
        }
        return time;
    }
};