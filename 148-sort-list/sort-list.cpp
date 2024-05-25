
class Solution {
public:
    ListNode* findMiddle(ListNode* head)
    {
        ListNode* slow=head;
        ListNode* fast=head->next;

        while(fast && fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* left,ListNode* right)
    {
        if(!left)
        {
            return right;
        }
        if(!right)
        {
            return left;
        }
        ListNode* temp=new ListNode(-1);
        ListNode* ans=temp;

        while(left && right)
        {
            if(left->val<right->val)
            {
                temp->next=left;
                temp=temp->next;
                left=left->next;
            }
            else
            {
                temp->next=right;
                temp=temp->next;
                right=right->next;
            }
        }

        while(left)
        {
            temp->next=left;
            temp=temp->next;
            left=left->next;
        }
        while(right)
        {
            temp->next=right;
            temp=temp->next;
            right=right->next;
        }
        return ans->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode* mid=findMiddle(head);
        ListNode* left=head;

        //create right half
        ListNode* right=mid->next;
        //break the left and right half
        mid->next=NULL;

        left=sortList(left);
        right=sortList(right);

        return merge(left,right);

    }
};