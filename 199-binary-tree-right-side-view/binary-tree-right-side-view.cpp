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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        vector<vector<int>>ans;

        if(root==NULL)
        {
            return res;
        }

        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            vector<int>output;

            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front();
                q.pop();

                output.push_back(node->val);

                if(node->left)
                {
                    q.push(node->left);
                }
                if(node->right)
                {
                    q.push(node->right);
                }                
            }
            ans.push_back(output);
        }

        for(auto i:ans)
        {
            res.push_back(i.back());
        }
        return res;
    }
};