class Solution {
public:
    string reversePrefix(string word, char ch) {
        //string ans='';
        int index=0;
        for(int i=0;i<word.size();i++)
        {
            if(word[i]==ch)
            {
                index=i;
                break;
            }
        }
        string rev=word.substr(0,index+1);
        reverse(rev.begin(),rev.end());
        rev=rev+word.substr(index+1,word.size());
        return rev;

    }
};