class Solution {
public:
    bool isPalindrome(string s) {
        string news;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>=65 && s[i]<=90)
            {
                news.push_back(s[i]+32);
            }
            if(s[i]>=97 && s[i]<=122)
            {
                news.push_back(s[i]);
            }
            if(s[i]>='0' && s[i]<='9')
            {
                news.push_back(s[i]);
            }
        }

        int i=0,j=news.size()-1;
        while(i<=j)
        {
            if(news[i++]!=news[j--])
            {
                return false;
                break;
            }
        }
        return true;
    }
};