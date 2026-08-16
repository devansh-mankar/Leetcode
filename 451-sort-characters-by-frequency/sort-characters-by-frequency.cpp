class Solution {
public:
    string frequencySort(string s) {
        int n=s.size();
        unordered_map<char,int>mp;

        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
        }

        vector<vector<char>>v(n+1);
        for(auto it:mp)
        {
            v[it.second].push_back(it.first);
        }

        string ans="";
        for(int fq=n;fq>=1;fq--)
        {
            for(auto ch:v[fq])
            {
                ans.append(fq,ch);
            }
        }
        return ans;
    }
};