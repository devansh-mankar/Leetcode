class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        int n=s.size();
        int m=t.size();

        vector<int>m1(26,0);
        vector<int>m2(26,0);

        for(int i=0;i<s.size();i++)
        {
            m1[s[i]-'a']++;
            m2[t[i]-'a']++;
        }

        for(int i=0;i<26;i++)
        {
            if(m1[i]!=m2[i]){
                return false;
            }
        }
        return true;
    }
};