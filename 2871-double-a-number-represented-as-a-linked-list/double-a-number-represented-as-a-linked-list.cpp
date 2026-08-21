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
        if(!head) return NULL;

        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp)
        {
            int value=temp->val*2;
            if(value<10)
            {
                temp->val=value;
            }
            else if(prev!=NULL)
            {
                temp->val=value%10;
                prev->val+=1;
            }
            else{
                ListNode* newNode=new ListNode(1);
                newNode->next=head;
                head=newNode;
                temp->val=value%10;
            }
            prev=temp;
            temp=temp->next;
        }
        return head;
    }
};