class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int a=0,b=0;
        vector<int>ans;

        for(auto it:seq)
        {
            if(it=='(')
            {
                if(a>b)
                {
                b++;
                ans.push_back(1);
                }
            else{
                a++;
                ans.push_back(0);
                }
            }
            else{
                if(b>a)
                {
                    b--;
                    ans.push_back(1);
                }
                else{
                    a--;
                    ans.push_back(0);
                }
            }
        }
        return ans;
    }
};