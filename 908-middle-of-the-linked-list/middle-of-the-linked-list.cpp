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
        if(!head || !head->next) return head;

        int count=0;
        ListNode* temp=head;
        while(temp)
        {
            count++;
            temp=temp->next;
        }

        temp=head;
        int i=0;
        int mid=0;
        mid=(count)/2;

        while(i<mid)
        {
            i++;
            temp=temp->next;
        }
        return temp;
    }
};