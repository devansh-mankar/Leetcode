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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next) return NULL;

        ListNode* temp=head;
        int count=0;
        while(temp)
        {
            count++;
            temp=temp->next;
        }

        int mid=0;
        if(count%2) mid=(count+1)/2;
        mid=count/2;
        int i=0;
        temp=head;
        while(i<mid-1)
        {
            i++;
            temp=temp->next;
        }

        temp->next=temp->next->next;
        return head;
    }
};