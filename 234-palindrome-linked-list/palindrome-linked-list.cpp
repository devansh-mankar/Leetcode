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
    ListNode* getMiddle(ListNode* head)
    {
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }

        return slow;
    }
    ListNode* Reverse(ListNode* head)
    {
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* forward=NULL;

        while(curr)
        {
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;

        ListNode* mid=getMiddle(head);
        ListNode* rev=Reverse(mid);
        mid->next=NULL;

        while(head && rev)
        {
            if(head->val!=rev->val)
            {
                return false;
            }
            head=head->next;
            rev=rev->next;
        }
        return true;
    }
};