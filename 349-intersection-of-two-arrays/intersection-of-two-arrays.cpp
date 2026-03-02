class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        set<int>s;

        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        int i=0,j=0;
        while(i<nums1.size() && j<nums2.size())
        {
            if(nums1[i]==nums2[j])
            {
                s.insert(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i]>nums2[j])
            {
                j++;
            }
            else{
                i++;
            }
        }


        for(auto it:s)
        {
            ans.push_back(it);
        }
        return ans;
    }
};