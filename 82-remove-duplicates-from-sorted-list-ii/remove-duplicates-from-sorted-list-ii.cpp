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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
        {
            return NULL;
        }

        ListNode dummy(0);
       
        ListNode* temp=head;
         dummy.next=head;
        ListNode* prev=&dummy;
       

        
        while(temp)
        {
            bool duplicate=false;
            while(temp->next && temp->val==temp->next->val)
            {
                duplicate=true;
                temp=temp->next;
            }
            if(duplicate)
            {
                prev->next=temp->next;
            }
            else{
                prev=prev->next;
            }
            
            temp=temp->next;
        }
        return dummy.next;
    }
};