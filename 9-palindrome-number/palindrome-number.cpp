class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
        {
            return 0;
        }
        long long rev=0;
        int num=x;

        while(x)
        {
            int rem=x%10;
            rev=rev*10+rem;
            x=x/10;
        }
        return (int)rev==num;
    }
};