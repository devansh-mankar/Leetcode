/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(int& index,int mini,int maxi,vector<int>&pre)
    {
        if(index>=pre.size())
        {
            return NULL;
        }
        if(pre[index]>=maxi || pre[index]<=mini)
        {
            return NULL;
        }
        TreeNode* temp=new TreeNode(pre[index++]);
        temp->left=solve(index,mini,temp->val,pre);
        temp->right=solve(index,temp->val,maxi,pre);
        return temp;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index=0;
        int mini=INT_MIN;
        int maxi=INT_MAX;
        return solve(index,mini,maxi,preorder);
    }
};