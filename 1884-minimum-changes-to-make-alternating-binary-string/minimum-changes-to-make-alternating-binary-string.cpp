class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        int curr1=0,curr2=0;

        for(int i=0;i<n;i++)
        {
            if(i%2==0 && s[i]!='0') curr1++;
            if(i%2!=0 && s[i]!='1') curr1++;
        }

        for(int i=0;i<n;i++)
        {
            if(i%2==0 && s[i]!='1') curr2++;
            if(i%2!=0 && s[i]!='0') curr2++;
        }

        return min(curr1,curr2);
    }
};