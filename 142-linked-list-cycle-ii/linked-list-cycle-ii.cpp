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
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return NULL;
        unordered_map<ListNode*,int>mp;


       ListNode* temp=head;
       int i=0;
       while(temp)
       {
            mp[temp]++;
            temp=temp->next;
            for(auto it:mp)
            {
                if(it.second==2)
                {
                    return it.first;
                }
            }
       }
       return NULL;

    }
};