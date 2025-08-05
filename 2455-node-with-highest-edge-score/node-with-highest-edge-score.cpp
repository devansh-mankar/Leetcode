class Solution {
public:
    int edgeScore(vector<int>& edges) {
        map<int,long long> m;
        for(int i=0;i<edges.size();i++)
        {
            m[edges[i]]+=i;
        }
        map<int,long long>::iterator itr=m.begin();
        int res=-1,mi=INT_MIN;
        while(itr != m.end())
        {
            if(itr->second>mi)
            {
                mi=itr->second;
                res=itr->first;
            }
            itr++;
        }
        return res;
    }
};