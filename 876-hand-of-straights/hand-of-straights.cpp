class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();

        if(n%groupSize!=0)
        {
            return false;
        }

        priority_queue<int,vector<int>,greater<int>>pq;
        unordered_map<int,int>mp;

        for(auto it:hand)
        {
            pq.push(it);
            mp[it]++;
        }

        while(!pq.empty())
        {
            int top=pq.top();
            pq.pop();
            //if element is not in map it has been removed as used in one of the groups
            if(mp.find(top)==mp.end())
            {
                continue;
            }

            for(int i=0;i<groupSize;i++)
            {
                if(mp.find(top+i)==mp.end())
                {
                    return false;
                }
                mp[top+i]--;
                if(mp[top+i]==0)
                {
                    mp.erase(top+i);
                }
            }
            
        }
        return true;
    }
};