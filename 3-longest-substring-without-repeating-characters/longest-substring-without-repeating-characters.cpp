class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int len=0;
        for(int i=0;i<n;i++)
        {
            vector<int>hash(256,-1);
            for(int j=i;j<n;j++)
            {
                if(hash[s[j]]==1)
                {
                   
                    break;
                }
                hash[s[j]]=1;
                 len=max(len,j-i+1);
            }
        }
        return len;
    }
};