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
    int solve(ListNode* head)
    {
        if(head==NULL)
        {
            return 0;
        }
        int doubleit=head->val*2+solve(head->next);
        head->val=doubleit%10;
        return doubleit/10;
    }
    ListNode* doubleIt(ListNode* head) {
        int carry=solve(head);

        if(carry)
        {
            head=new ListNode(carry,head);
        }
        return head;
    }
};