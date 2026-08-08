class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();

        set<vector<int>>s;

        for(int i=0;i<n;i++)
        {
           
            for(int j=i+1;j<n;j++)
            {
                
                unordered_map<long long,int>mp;
                for(int k=j+1;k<n;k++)
                {
                    long long num=1LL*target-nums[i]-nums[j]-nums[k];
                    if(mp.find(num)!=mp.end())
                    {
                        vector<int>temp={nums[i],nums[j],nums[k],nums[mp[num]]};
                        sort(temp.begin(),temp.end());
                        s.insert(temp);
                    }
                    mp[nums[k]]=k;
                }
            }
        }
        vector<vector<int>>ans(s.begin(),s.end());
        return ans;
    }
};