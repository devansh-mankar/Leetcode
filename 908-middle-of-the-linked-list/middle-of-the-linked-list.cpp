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
    ListNode* middleNode(ListNode* head) {
        if(!head || !head->next)
        {
            return head;
        }
        ListNode* temp=head;
        int count=1;
        while(temp)
        {
            count++;
            temp=temp->next;
        }
        int mid=0;
        if(count%2)
        {
            mid=(count/2)+1;
        }
        else{
            mid=count/2;
        }
        temp=head;
        for(int i=1;i<mid;i++)
        {
            temp=temp->next;
        }
        //temp=temp->next;
        return temp;
        
    }
};