class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        unordered_map<int,int>mp;
        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto it:mp)
        {
            pq.push({it.second,it.first});
        }

         while(pq.size()>k)
            {
                pq.pop();
            }
       while(!pq.empty())
       {
            ans.push_back(pq.top().second);
            pq.pop();
            
       }
       return ans;
    }
};