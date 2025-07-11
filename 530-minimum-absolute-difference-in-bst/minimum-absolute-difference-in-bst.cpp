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
    int mini=INT_MAX;
    int prev=-1;
    void solve(TreeNode* root)
    {
        if(root==NULL)
        {
            return;
        }
        solve(root->left);
        if(prev!=-1)
        {
            mini=min(mini,abs(prev-root->val));
        }
        prev=root->val;
        solve(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        solve(root);
        return mini;
    }
};