class Solution {
public:
    bool checkOnesSegment(string s) {
        int i0=0,i1=0;

        i0=s.find('0');
        if(i0==-1) return 1;

        i1=s.find_last_of('1');
        return i0>i1;
    }
};