class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            vector<int>hash(26,0);
            for(int j=i;j<n;j++)
            {
                hash[s[j]-'a']++;
                int mini=INT_MAX;
                int maxi=INT_MIN;

                for(int k=0;k<26;k++)
                {
                    if(hash[k]>0)
                    mini=min(mini,hash[k]);
                    maxi=max(maxi,hash[k]);
                }
                count+=(maxi-mini);
            }
        }
        return count;
    }
};