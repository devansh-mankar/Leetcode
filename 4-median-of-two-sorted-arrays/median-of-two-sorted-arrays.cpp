class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
         vector<int>temp;
        
        int i=0;
        int j=0;
        int n=nums1.size();
        int m=nums2.size();
        
        while(i<n && j<m)
        {
            if(nums1[i]<nums2[j])
            {
                temp.push_back(nums1[i++]);
            }
            else{
                temp.push_back(nums2[j++]);
            }
        }
        
        while(i<n)
        {
            temp.push_back(nums1[i++]);
        }
        while(j<m)
        {
            temp.push_back(nums2[j++]);
        }

        int size=n+m;
        if(size%2==1)
        {
            return (double)temp[size/2];
        }
        return ((double)temp[size/2]+(double)temp[size/2-1])/2.0;
    }
};