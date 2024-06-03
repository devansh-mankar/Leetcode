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
    int pairSum(ListNode* head) {
        vector<int>nums;
        ListNode* temp=head;
        int i=0;
        while(temp)
        {
            nums.push_back(temp->val);
            temp=temp->next;
        }
        int left=0,right=nums.size()-1;
        int ans=0;
        while(left<=right)
        {
            ans=max(ans,nums[left++]+nums[right--]);
        }
        return ans;
    }
};