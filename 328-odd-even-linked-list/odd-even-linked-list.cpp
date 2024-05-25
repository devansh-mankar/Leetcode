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
    ListNode* oddEvenList(ListNode* head) {

        if(head==NULL)
        {
            return NULL;
        }
        ListNode* temp=head;
        vector<int>arr;
        //storing odd indexes
        while(temp && temp->next)
        {
            arr.push_back(temp->val);
            temp=temp->next->next;
        }
        //if we have odd length linked list we need to check for the last node
        if(temp)
        {
            arr.push_back(temp->val);
        }
        //storing even indexes
        temp=head->next;
        while(temp && temp->next)
        {
            arr.push_back(temp->val);
            temp=temp->next->next;
        }
        if(temp)
        {
            arr.push_back(temp->val);
        }

        temp=head;
        int i=0;
        while(temp)
        {
            temp->val=arr[i++];
            temp=temp->next;
        }
        return head;

    }
};