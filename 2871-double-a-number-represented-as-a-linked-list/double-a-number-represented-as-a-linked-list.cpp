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
    ListNode* doubleIt(ListNode* head) {
      head=Reverse(head);
        int carry=0;

        ListNode* curr=head;
        ListNode* prev=NULL;

        while(curr)
        {
            int value=curr->val*2+carry;

            curr->val=value%10;
            if(value>9) carry=1;
            else carry=0;

            prev=curr;
            curr=curr->next;
        }

        if(carry!=0)
        {
            ListNode* newNode=new ListNode(carry);
            prev->next=newNode;
        }



        head=Reverse(head);
        return head;
    }
};