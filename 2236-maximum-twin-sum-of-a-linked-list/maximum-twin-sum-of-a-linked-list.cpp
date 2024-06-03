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
    ListNode* reverse(ListNode* head)
    {
        ListNode* curr=head;
        ListNode* prev=NULL;
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
    int pairSum(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast && fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        
        ListNode* rev=reverse(slow);
        slow->next=NULL;
        ListNode* temp1=head;
        int ans=0;
        while(temp1 && rev)
        {
            ans=max(ans,temp1->val+rev->val);
            temp1=temp1->next;
            rev=rev->next;
        }
        return ans;
    }
};