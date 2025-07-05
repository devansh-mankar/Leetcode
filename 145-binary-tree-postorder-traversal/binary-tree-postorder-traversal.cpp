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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==NULL)
        {
            return ans;
        }
        stack<TreeNode*>s;
        s.push(root);

        while(!s.empty())
        {
            auto node=s.top();
            s.pop();
              if(node->left)
            {
                s.push(node->left);
            }
           
            if(node->right)
            {
                s.push(node->right);
            }
            
           
            ans.push_back(node->val);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};