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
    ListNode* findMiddle(ListNode* head)
    {
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
        
    }
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev=NULL;
        ListNode* forward=NULL;
        ListNode* curr=head;

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

        
        
        ListNode* middle=findMiddle(head);
        
        ListNode* rev=reverse(middle);

        ListNode* second=rev;
        ListNode* first=head;


        while(first && second)
        {
            if(first->val!=second->val)
            {
                return false;
            }
            first=first->next;
            second=second->next;
        }
        return true;



    }
};