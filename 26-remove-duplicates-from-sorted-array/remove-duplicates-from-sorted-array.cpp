class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>s;
        int j=0;

        for(int i=0;i<n;i++)
        {
            if(s.find(nums[i])==s.end())
            {
                s.insert(nums[i]);
                nums[j++]=nums[i];
            }
        }
        return j;
    }
};