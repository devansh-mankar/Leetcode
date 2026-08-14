class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();

        int ind1=(n+m)/2;
        int ind2=ind1-1;
        int ele1=-1;
        int ele2=-1;
        int count=0;
        

        int i=0,j=0;
        while(i<n && j<m)
        {
            if(nums1[i]<=nums2[j])
            {
                if(count==ind1) ele1=nums1[i];
                if(count==ind2) ele2=nums1[i];
                count++;
                i++;
            }
            else{
                if(count==ind1) ele1=nums2[j];
                if(count==ind2) ele2=nums2[j];
                count++;
                j++;
            }
        }

        while(i<n)
        {
            if(count==ind1) ele1=nums1[i];
            if(count==ind2) ele2=nums1[i];
            i++;
            count++;
        }

        while(j<m)
        {
            if(count==ind1) ele1=nums2[j];
            if(count==ind2) ele2=nums2[j];
            j++;
            count++;
        }

        if((n+m)%2==1)
        {
            return (double)ele1;
        }
        return (double)(ele1+ele2)/2;
    }
};