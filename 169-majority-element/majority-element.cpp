class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //moore's voting algorithm

        //keeping track of minority and majority elements
        int n=nums.size();
        int cnt=0,ele=0;

        for(int i=0;i<n;i++)
        {
            if(cnt==0)
            {
                ele=nums[i];
            }
            if(ele==nums[i])
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
            

        }

       return ele;
    }

};