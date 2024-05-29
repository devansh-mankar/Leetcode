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
    ListNode* find(ListNode* temp,int k)
    {
        //starting from 1st node so decrement k
        k=k-1;
        while(k>0 && temp!=NULL)
        {
            k--;
            temp=temp->next;
        }
        return temp;
    }
    ListNode* reverseLL(ListNode* head)
    {
        ListNode* curr=head;
        ListNode* prev=NULL;
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
        ListNode* temp=head;
        ListNode* prevNode=NULL;
        ListNode* nextNode=NULL;

        while(temp)
        {
            //get the kth Node
            ListNode* kthNode=find(temp,k);
            //if the kth node is null
            if(kthNode==NULL)
            {
                //if previous group exists connect it
                if(prevNode)
                {
                    prevNode->next=temp;
                }
                break;
            }
            //store the next part after getting kth node so that we don't loose the track of linked list
            nextNode=kthNode->next;
            kthNode->next=NULL;
            //now reverse kth part
            reverseLL(temp);

            if(temp==head)
            {
                //adjusting the head after reversal
                head=kthNode;
            }
            else
            {
                //linking the last group of nodes to the reversed group
                prevNode->next=kthNode;
            }
            prevNode=temp;
            temp=nextNode;

        }
        return head;
    }
};