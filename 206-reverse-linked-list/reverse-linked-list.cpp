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
    ListNode* reverseList(ListNode* head) {
        if(!head) return NULL;

        vector<int>v;
        ListNode* temp=head;
        while(temp)
        {
            v.push_back(temp->val);
            temp=temp->next;
        }

        reverse(v.begin(),v.end());
        temp=head;

        for(int i=0;i<v.size();i++)
        {
            temp->val=v[i];
            temp=temp->next;
        }
        return head;
    }
};