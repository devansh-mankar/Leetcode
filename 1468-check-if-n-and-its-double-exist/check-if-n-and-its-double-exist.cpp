class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int,int>mp;

        for(auto it:arr)
        {
            if(mp[it*2] || (it%2==0 &&  mp[it/2])) return 1;
            else mp[it]++;
        }
        return false;
    }
};