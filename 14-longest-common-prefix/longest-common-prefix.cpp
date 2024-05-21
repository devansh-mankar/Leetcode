class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int n=strs.size();

        sort(strs.begin(),strs.end());

        string start=strs[0];
        string end=strs[n-1];

        for(int i=0;i<start.length();i++)
        {
            if(start[i]==end[i])
            {
                ans+=start[i];
            }
            else
            {
                return ans;
            }
        }
        return ans;
    }
};