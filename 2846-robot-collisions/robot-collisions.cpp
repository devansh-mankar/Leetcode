class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<int>indexes;
        int n=positions.size();

        for(int i=0;i<n;i++)
        {
            indexes.push_back(i);
        }

        auto compare=[&](int i1,int i2)
        {
            return positions[i1]<=positions[i2];
        };
        sort(indexes.begin(),indexes.end(),compare);

        stack<int>st;

        for(auto id:indexes)
        {
            if(directions[id]=='R')
            {
                st.push(id);
            }
            else
            {
                while(!st.empty() && healths[id]>0)
                {
                    if(healths[id]>healths[st.top()])
                    {
                        healths[id]--;
                        healths[st.top()]=0;
                        st.pop();
                    }
                    else if(healths[id]<healths[st.top()])
                    {
                        healths[st.top()]--;
                        healths[id]=0;
                    }
                    else
                    {
                        healths[id]=0;
                        healths[st.top()]=0;
                        st.pop();
                    }
                }
            }
        }

        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(healths[i]!=0)
            {
                ans.push_back(healths[i]);
            }
        }
        return ans;
        

    }
};