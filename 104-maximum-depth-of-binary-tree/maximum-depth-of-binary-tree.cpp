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
    int maxDepth(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        stack<pair<TreeNode*,int>>s;

        s.push({root,1});
        int maxi=0;
        while(!s.empty())
        {
            auto it=s.top();
            s.pop();

            maxi=max(maxi,it.second);
            if(it.first->left)
            {
                s.push({it.first->left,it.second+1});
                
            }
            if(it.first->right)
            {
                s.push({it.first->right,it.second+1});
            }
        }
        return maxi;
    }
};