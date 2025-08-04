class Solution {
public:
    void reverse(string& s,int start,int end)
    {
        while(start<end)
        {
            swap(s[start++],s[end--]);
        }
    }
    void removeSpaces(string& s)
    {
        int n=s.size();
        int i=0,j=0;

        //leading spaces
        while(i<n && s[i]==' ') i++;

        while(i<n)
        {
            if(s[i]!=' ')
            {
                s[j++]=s[i++];
            }
            else
            {
                s[j++]=' ';
                while(i<n && s[i]==' ') i++;
            }
        }

        if(j>0 && s[j-1]==' ') j--;

        s.resize(j);
    }
    string reverseWords(string s) {
        removeSpaces(s);
        int n=s.size();
        reverse(s,0,n-1);

        int start=0;
        for(int end=0;end<=n;end++)
        {
            if(end==n || s[end]==' ')
            {
                reverse(s,start,end-1);
                start=end+1;
            }
        }
        return s;
    }
};