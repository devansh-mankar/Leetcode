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
    pair<int,bool>solve(TreeNode* root)
    {
        if(root==NULL)
        {
            return {0,1};
        }
        pair<int,bool>left=solve(root->left);
        pair<int,bool>right=solve(root->right);

        bool leftCheck=left.second;
        bool rightCheck=right.second;

        bool diff=abs(left.first-right.first)<=1;

        pair<int,bool>temp;
        temp.first=max(left.first,right.first)+1;
        if(diff && leftCheck && rightCheck)
        {
            temp.second=true;
        }
        else{
            temp.second=false;
        }
        return temp;
    }
    bool isBalanced(TreeNode* root) {
        pair<int,bool>p=solve(root);
        return p.second;
    }
};