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
    void solve(TreeNode* root,vector<int>&count)
    {
        if(root==NULL)
        {
            return;
        }
        solve(root->left,count);
        count.push_back(root->val);
        solve(root->right,count);
    }
    int countNodes(TreeNode* root) {
        vector<int>count;
        solve(root,count);
        return count.size();
    }
};