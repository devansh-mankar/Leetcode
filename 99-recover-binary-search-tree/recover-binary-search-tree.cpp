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
    void solve(TreeNode* root,vector<int>&inorder)
    {
        if(root==NULL)
        {
            return;
        }
        solve(root->left,inorder);
        inorder.push_back(root->val);
        solve(root->right,inorder);
    }

    int i=0;
    void check(TreeNode* root,vector<int>&inorder)
    {
        if(root==NULL)
        {
            return;
        }
        check(root->left,inorder);
        if(inorder[i]!=root->val)
        {
            swap(inorder[i],root->val);
        }
        i++;
        check(root->right,inorder);
    }
    void recoverTree(TreeNode* root) {
        vector<int>inorder;
        solve(root,inorder);
        sort(inorder.begin(),inorder.end());
        check(root,inorder);
        
    }
};