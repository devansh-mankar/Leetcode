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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>index;
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* forward=head->next;
        int count=0;

        while(curr)
        {
            if(prev && forward)
            {
                 if(curr->val>forward->val && curr->val>prev->val || curr->val<forward->val && curr->val<prev->val)
                {
                    index.push_back(count);
                }
            }
            
            prev=curr;
            
            curr=curr->next;
            if(curr->next==NULL)
            {   
                break;
            }
            forward=curr->next;
            count++;


          
        }

          if(index.size()<2)
            {
                return {-1,-1};
            }
            int maxi=INT_MIN;
             maxi=abs(index[index.size()-1]-index[0]);
            int mini=INT_MAX;
            for(int i=0;i<index.size()-1;i++)
            {
                mini=min(mini,abs(index[i]-index[i+1]));
            }
            return {mini,maxi};
    }
};