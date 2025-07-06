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
    int height(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int left=1+height(root->left);
        int right=1+height(root->right);
        return max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
        {
            return true;
        }
        int leftH=height(root->left);
        int rightH=height(root->right);

        if(abs(leftH-rightH)<=1 && isBalanced(root->left) && isBalanced(root->right))
        {
            return true;
        }
        return false;
    }
};