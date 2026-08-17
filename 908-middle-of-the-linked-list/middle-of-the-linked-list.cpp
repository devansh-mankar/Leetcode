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
    ListNode* middleNode(ListNode* head) {
        if(!head || !head->next)
        {
            return head;
        }
        int len=0;
        ListNode* temp=head;
        while(temp)
        {
            len++;
            temp=temp->next;
        }
        int mid=0;
        if(len%2) mid=(len+1)/2;
        mid=len/2;

        int i=0;
        temp=head;
        while(i<mid)
        {
            temp=temp->next;
            i++;
        }

        return temp;
    }
};