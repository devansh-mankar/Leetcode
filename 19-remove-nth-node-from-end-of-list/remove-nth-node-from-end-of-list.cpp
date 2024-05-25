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
        vector<ListNode*>v;
        ListNode* temp=head;

        while(temp)
        {
            v.push_back(temp);
            temp=temp->next;
        }
        if(v.size()==1)
        {
            return NULL;
        }
        if(v.size()-n<=0)
        {
            return head->next;
        }

        ListNode* node=v[v.size()-1-n];
        node->next=node->next->next;
        return head;
    }
};