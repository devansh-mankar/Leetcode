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
        ListNode* temp=head;
        map<ListNode*,int>vis;

        while(temp)
        {
            vis[temp]++;
            temp=temp->next;

             for(auto it:vis)
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