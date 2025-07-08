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
        vector<int>view;
        if(root==NULL)
        {
            return view;
        }
        map<int,int>mp;
        queue<pair<TreeNode*,int>>q;

        q.push({root,0});

        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            TreeNode* node=it.first;
            int lvl=it.second;

            mp[lvl]=node->val;

            if(node->left)
            {
                q.push({node->left,lvl+1});
            }
            if(node->right)
            {
                q.push({node->right,lvl+1});
            }

        }

        for(auto i:mp)
        {
            view.push_back(i.second);
        }
        return view;
    }
};