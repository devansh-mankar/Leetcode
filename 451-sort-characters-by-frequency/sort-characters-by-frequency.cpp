class Solution {
public:
    string frequencySort(string s) {
        int n=s.size();

        map<char,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
        }
        vector<pair<int,char>>v;
        for(auto it:mp)
        {
            v.push_back({it.second,it.first});
        }

        sort(v.begin(),v.end(),greater<pair<int,char>>());
        string ans="";
        for(int i=0;i<v.size();i++)
        {
            string temp(v[i].first,v[i].second);
            ans+=temp;
        }
        return ans;
    }
};