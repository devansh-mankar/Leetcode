class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();

        unordered_set<int>s;

        if(n==0)
        {
            return 0;
        }

        for(int i=0;i<n;i++)
        {
            s.insert(nums[i]);
        }

        

        int longest=1;

        for(auto it:s)
        {
            if(s.find(it-1)==s.end())
            {
                int x=it;
                int cnt=1;

                while(s.find(x+1)!=s.end())
                {
                    x++;
                    cnt++;
                }
                longest=max(longest,cnt);
            }
        }
        return longest;
    }
};