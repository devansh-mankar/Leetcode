class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        priority_queue<pair<int,int>>max_heap;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)mp[nums[i]]++;
        for(auto it=mp.begin();it!=mp.end();it++){
            max_heap.push({-it->second,it->first});
        }
        // vector<int>ans;
        int k=0;
        while(max_heap.size()>0){
        int x = max_heap.top().first;
            for(int i=0;i<abs(x);i++)nums[k++] = (max_heap.top().second);
            max_heap.pop();
        }
        // reverse(ans.begin(),ans.end());
        return nums;
    }
};