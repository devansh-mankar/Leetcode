/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;

        vector<int>temp;
        while(head)
        {
            temp.push_back(head->val);
            head=head->next;
        }
        

        int n=temp.size();
        int i=0;
        int j=n-1;
        while(i<=j)
        {
            if(temp[i++]!=temp[j--])
            {
                return false;
            }
        }
        return true;
    }
};