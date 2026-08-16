class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size())
        {
            return false;
        }
        s=s+s;
        if(s.find(goal)!=std::string::npos)
        {
            return true;
        }
        return false;
        
    }
};