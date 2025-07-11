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
    void solve(TreeNode* root,vector<int>&in)
    {
        if(root==NULL)
        {
            return;
        }
        solve(root->left,in);
        in.push_back(root->val);
        solve(root->right,in);
    }
        int i=0;
    void check(TreeNode* root,vector<int>&in)
    {
        if(root==NULL)
        {
            return;
        }
        check(root->left,in);
        if(in[i]!=root->val)
        {
            swap(in[i],root->val);
        }
        i++;
        check(root->right,in);
    }
    void recoverTree(TreeNode* root) {
        vector<int>in;
        solve(root,in);
        sort(in.begin(),in.end());
        check(root,in);
    }
};