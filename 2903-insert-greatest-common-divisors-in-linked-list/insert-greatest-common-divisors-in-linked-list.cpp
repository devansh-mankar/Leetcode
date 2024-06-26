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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr=head;
        ListNode* forward=curr->next;

        while(curr && forward)
        {
            int value=__gcd(curr->val,forward->val);
            ListNode* newnode=new ListNode(value);
            newnode->next=forward;
            curr->next=newnode;
            
            curr=curr->next->next;
            forward=forward->next;
        }
        return head;
    }
};