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
    pair<int,int>solve(TreeNode* root)
    {
        if(root==NULL)
        {
            return {0,0};
        }
        pair<int,int>left=solve(root->left);
        pair<int,int>right=solve(root->right);

        int op1=left.second;
        int op2=right.second;
        int op3=left.first+right.first+1;

        pair<int,int>temp;
        temp.first=max(left.first,right.first)+1;
        temp.second=max({op1,op2,op3});
        return temp;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int,int>p=solve(root);
        return p.second-1;
    }
};