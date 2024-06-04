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
    int numComponents(ListNode* head, vector<int>& nums) {
        map<int,int>mp;
        ListNode* temp=head;

        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        int count=0;
        while(temp)
        {
            if(mp[temp->val]!=0)
            {
                while(temp->next && mp[temp->next->val]!=0)
                {
                    temp=temp->next;
                }
                count++;
            }
            temp=temp->next;
        }
        return count;
    }
};