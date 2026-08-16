class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n=seq.size();
        int open=0;

        vector<int>v(n);
        for(int i=0;i<n;i++)
        {
            if(seq[i]=='(')
            {
                v[i]=open&1;
                open++;
            }
            else{
                open--;
                v[i]=open&1;
            }
        }
        return v;
    }
};