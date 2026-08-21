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
        if(!head)
        {
            return NULL;
        }
        head=Reverse(head);

        int carry=0;
        ListNode* temp=head;
        ListNode* last=NULL;
        while(temp)
        {
            int value=temp->val*2+carry;
            temp->val=value%10;
            if(value<10)
            {
                carry=0;
            }
            else{
                carry=1;
            }
            last=temp;
            temp=temp->next;
        }


        if(carry!=0)
        {
            ListNode* newNode=new ListNode(carry);
            last->next=newNode;
        }

        head=Reverse(head);
        return head;
    }
};