/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next) return false;
        unordered_map<ListNode*,int>mp;

        ListNode* temp=head;
        while(temp)
        {
            if(mp[temp])
            {
                return true;
            }
            mp[temp]=1;
            temp=temp->next;
        }
        return false;


    }
};