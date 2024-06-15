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
            TreeNode* temp=q.front();
            q.pop();

            if(temp->left)
            {
                q.push(temp->left);
                nodeToParent[temp->left]=temp;
            }
            if(temp->right)
            {
                q.push(temp->right);
                nodeToParent[temp->right]=temp;
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
            int size=q.size();
            while(size--)
            {
                TreeNode* temp=q.front();
                q.pop();

                if(temp->left && !vis[temp->left])
                {
                    vis[temp->left]=true;
                    q.push(temp->left);
                }
                if(temp->right && !vis[temp->right])
                {
                    vis[temp->right]=true;
                    q.push(temp->right);
                }
                if(!vis[nodeToParent[temp]] && nodeToParent[temp])
                {
                    vis[nodeToParent[temp]]=true;
                    q.push(nodeToParent[temp]);
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