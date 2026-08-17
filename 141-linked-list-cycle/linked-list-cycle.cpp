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
        map<ListNode*,bool>mp;

        while(head)
        {
            if(mp[head])
            {
                return true;
                break;
            }
            mp[head]=true;
            head=head->next;
        }
        return false;
    }
};