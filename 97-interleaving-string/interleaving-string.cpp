class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.size(),n2=s2.size(),n3=s3.size();

        vector<int>curr(n2+1,0);
        vector<int>prev(n2+1,0);

        if(n3!=n1+n2)
        {
            return false;
        }


        for(int i=n1;i>=0;i--)
        {
            for(int j=n2;j>=0;j--)
            {
                int k=i+j;
                if(i==n1 && j==n2)
                {
                    curr[j]=1;
                }
                else if(s3[k]==s1[i] && s3[k]==s2[j])
                {
                    curr[j]=curr[j+1] || prev[j];
                }
                else if(s3[k]==s1[i])
                {
                    curr[j]=prev[j];
                }
                else if(s3[k]==s2[j])
                {
                    curr[j]=curr[j+1];
                }
                else{
                    curr[j]=false;
                }
            }
            prev=curr;
        }

        return  curr[0];
    }
};