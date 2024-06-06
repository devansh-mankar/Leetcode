class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        map<char,int>mp;
        for(int i=0;i<m;i++)
        {
            mp[t[i]]++;
        }
        int left=0,right=0,index=-1;
        int minlen=INT_MAX,count=0;
        while(right<n)
        {
            if(mp[s[right]]>0)
            {
                count++;
            }
            mp[s[right]]--;
            while(count==m)
            {
                if((right-left+1)<minlen)
                {
                    minlen=right-left+1;
                    index=left;
                }
                mp[s[left]]++;
                if(mp[s[left]]>0)
                {
                    count--;
                }
                left++;
            }
            right++;
        }
        if(minlen==INT_MAX)
        {
            return "";
        }
        return s.substr(index,minlen);
    }
};