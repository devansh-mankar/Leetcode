class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n=seq.size();
        int a=0,b=0;
        vector<int>ans;

        for(auto it:seq)
        {
            if(it=='(')
            {
                if(a<=b)
                {
                    a++;
                    ans.push_back(0);
                }
                else{
                    b++;
                    ans.push_back(1);
                }
            }
            else{
                if(a>b)
                {
                    a--;
                    ans.push_back(0);
                }
                else{
                    b--;
                    ans.push_back(1);
                }
            }
        }
        return ans;
    }
};