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
        if(!head) return 0;
       
        int value=2*head->val+solve(head->next);

        head->val=value%10;
        return value/10;
    }
    ListNode* doubleIt(ListNode* head) {
        int carry=solve(head);

        if(carry)
        {
            ListNode* newNode=new ListNode(1);
            newNode->next=head;
            head=newNode;
        }
        return head;
    }
};