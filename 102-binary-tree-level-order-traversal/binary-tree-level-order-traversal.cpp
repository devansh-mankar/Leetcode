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
    void solve(TreeNode* root,vector<vector<int>>&ans,int level)
    {
        if(root==NULL)
        {
            return;
        }
        if(level>=ans.size())
        {
            ans.resize(level+1);
        }
        ans[level].push_back(root->val);
        solve(root->left,ans,level+1);
        solve(root->right,ans,level+1);

    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
         solve(root,ans,0);
         return ans;
    }
};