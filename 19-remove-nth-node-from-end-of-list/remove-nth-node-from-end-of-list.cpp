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
        if(!head || !head->next) return NULL;
        int count=0;
        ListNode* temp=head;

        while(temp)
        {
            count++;
            temp=temp->next;
        }

        if(count==n)
        {
            //remove the head
            head=head->next;
            return head;
        }

        int node=count-n;
        temp=head;
        int i=0;
        while(i<node-1)
        {
            i++;
            temp=temp->next;
        }
        if(temp->next)
        temp->next=temp->next->next;
        return head;
    }
};