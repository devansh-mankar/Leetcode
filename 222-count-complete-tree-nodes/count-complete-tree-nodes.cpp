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
    int leftHeight(TreeNode* root)
    {
        int count=0;
        while(root)
        {
            count++;
            root=root->left;
        }
        return count;
    }
    int rightHeight(TreeNode* root)
    {
        int count=0;
        while(root)
        {
            count++;
            root=root->right;
        }
        return count;
    }
    int countNodes(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        int leftH=leftHeight(root);
        int rightH=rightHeight(root);

        if(leftH==rightH)
        {
            return (1<<leftH)-1;
        }
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};