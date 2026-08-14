class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();

        int i=0;
        int j=0;
        int n=(n1+n2);

        int ele1=-1;
        int ele2=-1;
        int count=0;
        int ind1=n/2;
        int ind2=ind1-1;

        while(i<n1 && j<n2)
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

        while(i<n1)
        {
            if(count==ind1) ele1=nums1[i];
            if(count==ind2) ele2=nums1[i];
            i++;
            count++;
        }

        while(j<n2)
        {
            if(count==ind1) ele1=nums2[j];
            if(count==ind2) ele2=nums2[j];
            j++;
            count++;
        }

        if(n%2==1)
        {
            return (double)(ele1);
        }
        return (double)(ele1+ele2)/2;

    }
};