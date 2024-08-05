class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        int ans=0;
        for(int i=0;i<n;i++)
        {
            map<int,int>mp;
            for(int j=0;j<pick.size();j++)
            {
                if(pick[j][0]==i)
                {
                    mp[pick[j][1]]++;
                    if(mp[pick[j][1]]>i)
                    {
                        ans++;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};