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
    int getMinimumDifference(TreeNode* root) {
        vector<int>in;
        solve(root,in);
        int mini=INT_MAX;
        for(int i=1;i<in.size();i++)
        {
            mini=min(mini,abs(in[i]-in[i-1]));
        }
        return mini;
    }
};