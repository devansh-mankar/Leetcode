class Solution {
public:
    int maxDepth(string s) {
        int n=s.size();
        int maxi=-1;
        int count=0;
        for(auto it:s)
        {
            if(it=='(')
            {
                count++;
            }
            maxi=max(maxi,count);
            if(it==')')
            {
                count--;
            }
        }
        return maxi;
    }
};