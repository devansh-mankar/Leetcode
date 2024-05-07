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
    ListNode* doubleIt(ListNode* head) {
        stack<int>s;
        int val=0;

        while(head!=NULL)
        {
            s.push(head->val);
            head=head->next;
        }

        ListNode* newHead=NULL;

        while(!s.empty() || val!=0)
        {
            newHead=new ListNode(0,newHead);
            if(!s.empty())
            {
                val+=s.top()*2;
                s.pop();
            }
            newHead->val=val%10;
            val=val/10;
        }
        return newHead;


    }
};