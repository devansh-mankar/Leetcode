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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp=head;
        int count=0;
        while(temp)
        {
            count++;
            temp=temp->next;
        }
        ListNode* a=head;
        ListNode* b=head;

        for(int i=0;i<k-1;i++)
        {
            a=a->next;
        }
        for(int i=0;i<count-k;i++)
        {
            b=b->next;
        }
        swap(a->val,b->val);
        return head;
    }
};