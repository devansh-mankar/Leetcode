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
    TreeNode* getMin(TreeNode* root)
    {
        while(root->left)
        {
            root=root->left;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)
        {
            return NULL;
        }
        if(root->val==key)
        {
            //if it is leaf node
            if(!root->left && !root->right)
            {
                delete root;
                return NULL;
            }
            //if single child present

            //right child is present
           else if(!root->left && root->right)
            {
                TreeNode* temp=root->right;
                delete root;
                return temp;
            }

            //left child is present
            else if(!root->right && root->left)
            {
                TreeNode* temp=root->left;
                delete root;
                return temp;
            }
            else
            {
                int mini=getMin(root->right)->val;
                root->val=mini;

                root->right=deleteNode(root->right,mini);
                return root;
            }
        }
        else if(root->val>key)
        {
            root->left=deleteNode(root->left,key);
        }
        else
        {
            root->right=deleteNode(root->right,key);
        }
        return root;
    }
};