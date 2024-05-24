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
        map<ListNode*,int>vis;

        while(head!=NULL)
        {
            vis[head]++;
            head=head->next;

            for(auto &it:vis)
        {
            if(it.second==2)
            {
                return it.first;
                break;
            }
        }
        }

        
        return 0;
    }
};