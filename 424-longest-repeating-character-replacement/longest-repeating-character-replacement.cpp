class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int changes=0,maxlen=0;

        for(int i=0;i<n;i++)
        {
            int hash[26]={0};
            int maxFreq=0;
            for(int j=i;j<n;j++)
            {
                hash[s[j]-'A']++;
                maxFreq=max(maxFreq,hash[s[j]-'A']);
                changes=(j-i+1)-maxFreq;

                if(changes<=k)
                {
                    maxlen=max(maxlen,j-i+1);
                }
                else
                {
                    break;
                }
            }
        }
        return maxlen;
    }
};