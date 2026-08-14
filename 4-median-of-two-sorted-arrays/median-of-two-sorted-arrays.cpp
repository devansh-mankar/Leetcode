class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();

        vector<int>temp;
        int i=0;
        int j=0;
        while(i<n1 && j<n2)
        {
            if(nums1[i]<=nums2[j])
            {
                temp.push_back(nums1[i++]);
            }
            else{
                temp.push_back(nums2[j++]);
            }
        }

        while(i<n1)
        {
            temp.push_back(nums1[i++]);
        }
        while(j<n2)
        {
            temp.push_back(nums2[j++]);
        }
        int n=temp.size();
        if((n1+n2)%2==1)
        {
            return (double)temp[n/2];
        }
        return (double)(temp[n/2]+temp[n/2-1])/2;
    }
};