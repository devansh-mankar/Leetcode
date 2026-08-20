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
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next)
        {
            return head;
        }

        ListNode* first=head;
        while(first)
        {
            ListNode* temp=first->next;
            while(temp)
            {
                if(first->val>temp->val)
                {
                    swap(first->val,temp->val);
                }
                temp=temp->next;
            }
            first=first->next;
        }
        return head;
    }
};