class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;

        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            pq.push(nums[i]);
        }
        int count=n-k;
        while(count--)
        {
            pq.pop();
        }
        return pq.top();
    }
};