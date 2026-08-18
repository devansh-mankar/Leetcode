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
    ListNode* merge(ListNode* left,ListNode* right)
    {
        if(!left) return right;
        if(!right) return left;

        ListNode* temp=new ListNode(0);
        ListNode* ans=temp;

        while(left && right)
        {
            if(left->val<=right->val)
            {
                temp->next=left;
                temp=temp->next;
                left=left->next;
            }
            else{
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
    ListNode* getMiddle(ListNode* head)
    {
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=NULL;

        while(fast && fast->next)
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        return prev;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
        {
            return head;
        }
        ListNode* mid=getMiddle(head);
        ListNode* left=head;
        ListNode* right=mid->next;
        mid->next=NULL;

        left=sortList(left);
        right=sortList(right);

        return merge(left,right);
    }
};