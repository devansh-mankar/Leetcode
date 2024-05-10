class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>st;
        int n=nums.size();
        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++)
        {
            //to avoid duplicates
            if(i!=0 && nums[i]==nums[i-1])
            {
                continue;
            }
            int j=i+1;
            int k=n-1;
            while(j<k)
            {
                int sum=nums[i]+nums[j]+nums[k];
                if(sum>0)
                {
                    k--;
                }
                else if(sum<0)
                {
                    j++;
                }
                else
                {
                    vector<int>temp={nums[i],nums[j],nums[k]};
                    st.insert(temp);
                    j++;
                    k--;
                }

            }
        }

        vector<vector<int>>ans(st.begin(),st.end());
        return ans;
    }
};