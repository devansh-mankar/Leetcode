class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0,right=0,maxlen=0;
        int length=0;
        int n=s.size();
        vector<int>hash(256,-1);
       
        while(right<n)
        {
            if(hash[s[right]]!=-1)
            { 
              left= max(hash[s[right]]+1,left);
            }
             hash[s[right]]=right;
            length=right-left+1;
            maxlen=max(maxlen,length);
            right++;
        }
        return maxlen;
    }
};