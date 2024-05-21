class Solution {
public:
    string reverseWords(string s) {
        int left=0,right=s.length()-1;
        string ans="";
        string temp="";
        while(left<=right)
        {
            char ch=s[left];
            if(ch!=' ')
            {
                temp+=ch;
            }
            else if(ch==' ')
            {
                if(ans!="")
                {
                    ans=temp+(temp=="" ? "":" ")+ans;
                }
                else
                {
                    ans=temp;
                    
                }
                temp="";
            }
            left++;
        }

        if(temp!="")
        {
            if(ans!="")
            {
                ans=temp+" "+ans;
            }
            else{
                ans=temp;
            }
        }
        return ans;
    }
};