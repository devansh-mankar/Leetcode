class Solution {
public:
    bool solve(string s1,string s2,string order)
    {
        for(int i=0;i<min(s1.size(),s2.size());i++)
        {
            int index1=order.find(s1[i]);
            int index2=order.find(s2[i]);

            if(index1==index2)
            {
                continue;
            }
            return index1<index2;
        }
        return s1.size()<=s2.size();
    }
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i=0;i<words.size()-1;i++)
        {
            if(!solve(words[i],words[i+1],order))
            {
                return false;
            }
        }
        return true;
    }
};