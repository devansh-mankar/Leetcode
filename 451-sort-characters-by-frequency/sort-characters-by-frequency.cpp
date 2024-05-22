class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(auto c:s)
        {
            mp[c]++;
        }

        vector<vector<char>>bucket(s.length()+1);

        for(auto [ch,fq]:mp)
        {
            bucket[fq].push_back(ch);
        }

        string ans="";
        for(int i=s.length();i>=0;i--)
        {
            for(auto ch:bucket[i])
            {
                ans.append(i,ch);
            }
        }
        return ans;
    }
};