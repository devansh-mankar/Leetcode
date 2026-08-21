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
    ListNode* findK(ListNode* head,int k)
    {
        k--;
        while(k>0 && head)
        {
            k--;
            head=head->next;
        }
        return head;
    }
    ListNode* Reverse(ListNode* head)
    {
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* forward=NULL;

        while(curr)
        {
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k==1) return head;

        ListNode* temp=head;
        ListNode* prevLast=NULL;
        ListNode* nextNode=NULL;
        while(temp)
        {
            ListNode* kth=findK(temp,k);
            if(kth==NULL)
            {
                if(prevLast)
                {
                    prevLast->next=temp;
                }
                break;
            }
            nextNode=kth->next;
            kth->next=NULL;
            Reverse(temp);
            if(temp==head)
            {
                head=kth;
            }
            else{
                prevLast->next=kth;
            }
            prevLast=temp;
            temp=nextNode;  
        }
        return head;
    }
};