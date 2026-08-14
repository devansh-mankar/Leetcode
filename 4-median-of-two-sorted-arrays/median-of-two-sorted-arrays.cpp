class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();

        vector<int>temp;
        for(int i=0;i<n;i++)
        {
            temp.push_back(nums1[i]);
        }
        for(int j=0;j<m;j++)
        {
            temp.push_back(nums2[j]);
        }
        sort(temp.begin(),temp.end());
        int size=temp.size();
        if(size%2==1)
        {
            return (double)temp[size/2];
        }
        return (double)(temp[size/2-1]+temp[size/2])/2;
    }
};