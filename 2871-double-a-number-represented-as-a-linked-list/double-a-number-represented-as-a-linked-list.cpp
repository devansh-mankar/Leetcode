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
    ListNode* doubleIt(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* curr=head;

        while(curr)
        {
            int val=2*curr->val;

            if(val<10)
            {
                curr->val=val;
            }

            else if(prev!=NULL)
            {
                curr->val=val%10;
                prev->val=prev->val+1;
            }

            else
            {
                //first node we need to create a new node
                head=new ListNode(1,curr);
                curr->val=val%10;
            }
            prev=curr;
            curr=curr->next;
        }
        return head;
    }
};