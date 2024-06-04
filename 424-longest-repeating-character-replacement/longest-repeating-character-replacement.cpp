class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int left=0,right=0;
        int maxlen=0;
        int maxFreq=0;
        vector<int>hash(26,0);

        while(right<n)
        {
            hash[s[right]-'A']++;
            maxFreq=max(maxFreq,hash[s[right]-'A']);

            if(((right-left+1)-maxFreq)>k)
            {
                hash[s[left]-'A']--;
                left++;
            }
            if(((right-left+1)-maxFreq)<=k)
            {
                maxlen=max(maxlen,right-left+1);
            }
            right++;
        }
        return maxlen;
    }
};