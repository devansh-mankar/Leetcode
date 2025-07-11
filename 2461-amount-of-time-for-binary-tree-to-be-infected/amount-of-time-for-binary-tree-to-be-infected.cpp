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
     TreeNode* findStart(TreeNode* root, int start) {
        if (!root) return nullptr;
        if (root->val == start) return root;
        
        TreeNode* left = findStart(root->left, start);
        if (left) return left;
        
        return findStart(root->right, start);
    }
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
            int size=q.size();
            while(size--)
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
    }
    int solve(TreeNode* start,unordered_map<TreeNode*,TreeNode*>&nodeToParent)
    {
        int time=0;
        unordered_map<TreeNode*,int>vis;
        queue<TreeNode*>q;
        q.push(start);
        vis[start]=true;

        while(!q.empty())
        {
            int n=q.size();
            bool flag=0;
            while(n--)
            {
                auto node=q.front();
                q.pop();

                if(node->left && !vis[node->left])
                {
                    flag=1;
                    vis[node->left]=true;
                    q.push(node->left);
                }
                if(node->right && !vis[node->right])
                {
                    flag=1;
                    vis[node->right]=true;
                    q.push(node->right);
                }
                if(nodeToParent[node] && !vis[nodeToParent[node]])
                {
                    flag=1;
                    vis[nodeToParent[node]]=true;
                    q.push(nodeToParent[node]);
                }
            }
            if(flag==1)
            {
                time++;
            }
        }
        return time;
    }
    int amountOfTime(TreeNode* root, int start) {
      TreeNode* temp= findStart(root,start);
        unordered_map<TreeNode*,TreeNode*>nodeToParent;
        findParent(root,nodeToParent);
        return solve(temp,nodeToParent);
    }
};