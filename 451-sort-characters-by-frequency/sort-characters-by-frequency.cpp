class Solution {
public:
    string frequencySort(string s) {
        int n=s.size();

        map<char,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
        }

        vector<vector<char>>v(s.length()+1);

        for(auto it:mp)
        {
            v[it.second].push_back(it.first);
        }

        string ans="";
        for(int i=n;i>=1;i--)
        {
            for(auto it:v[i])
            {
                ans.append(i,it);
            }
        }
        return ans;
    }
};