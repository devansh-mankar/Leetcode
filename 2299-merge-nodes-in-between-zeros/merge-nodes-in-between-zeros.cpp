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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp=head->next;
        ListNode* dummy=new ListNode(0);
        ListNode* head1=dummy;
        
        while(temp)
        {
            int value=0;
            while(temp->val!=0)
            {
                value+=temp->val;
                temp=temp->next;
            }
            ListNode* newnode=new ListNode(value);
            dummy->next=newnode;
            dummy=newnode;
            temp=temp->next;

        }
        return head1->next;
    }
};