/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void findParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&nodeToParent)
    {
        if(root==NULL)
        {
            return;
        }
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            auto node=q.front();
            q.pop();

            if(node->left)
            {
                q.push(node->left);
                nodeToParent[node->left]=node;
            }
            if(node->right)
            {
                q.push(node->right);
                nodeToParent[node->right]=node;
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        unordered_map<TreeNode*,TreeNode*>nodeToParent;

        findParent(root,nodeToParent);

        unordered_map<TreeNode*,int>vis;
        vis[target]=true;

        queue<TreeNode*>q;
        q.push(target);

        while(k--)
        {
            int n=q.size();
            while(n--)
            {
                auto node=q.front();
                q.pop();

                if(node->left && !vis[node->left])
                {
                    q.push(node->left);
                    vis[node->left]=true;
                }
                if(node->right && !vis[node->right])
                {
                    q.push(node->right);
                    vis[node->right]=true;
                }
                if(nodeToParent[node] && !vis[nodeToParent[node]])
                {
                    q.push(nodeToParent[node]);
                    vis[nodeToParent[node]]=true;
                }
            }
        }

        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};