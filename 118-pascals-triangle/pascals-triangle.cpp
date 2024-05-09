class Solution {
public:
    vector<int>generateRows(int row)
    {
        long long res=1;
        vector<int>temp;
        //first row
        temp.push_back(1);
        for(int col=1;col<row;col++)
        {
            res=res*(row-col);
            res=res/col;
            temp.push_back(res);
        }   
        return temp;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=1;i<=numRows;i++)
        {
            ans.push_back(generateRows(i));
        }
        return ans;
    }
};