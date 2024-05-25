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
        ListNode* temp=head;
        int count=0;
        if(head==NULL)
        {
            return NULL;
        }
       

        while(temp)
        {
            count++;
            temp=temp->next;
        }

       if(count==0)
       {
        return NULL;
       }
       if(count==n)
       {
        return head->next;
       }

        int e=count-n;
        temp=head;
        count=0;

        while(temp)
        {
            count++;
            if(count==e)
            {
                temp->next=temp->next->next;
            }
            
            temp=temp->next;
        }

        return head;

    }
};