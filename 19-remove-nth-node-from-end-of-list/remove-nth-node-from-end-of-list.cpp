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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || !head->next)
        {
            return NULL;
        }

        int count=1;
        ListNode* temp=head;
        while(temp->next)
        {
            count++;
            temp=temp->next;
        }

        if(count==n) return head->next;

        int pos=count-n;
        int i=0;
        temp=head;
        while(i<pos-1)
        {
            i++;
            temp=temp->next;
        }
        temp->next=temp->next->next;
        return head;
    }
};