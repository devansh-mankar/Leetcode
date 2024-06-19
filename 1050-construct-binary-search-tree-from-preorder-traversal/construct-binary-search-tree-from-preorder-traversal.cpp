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
    TreeNode* solve(vector<int>&pre,int& index,int mini,int maxi)
    {
        if(index>=pre.size())
        {
            return NULL;
        }
        if(pre[index]<=mini || pre[index]>=maxi)
        {
            return NULL;
        }
        TreeNode* temp=new TreeNode(pre[index++]);
        temp->left=solve(pre,index,mini,temp->val);
        temp->right=solve(pre,index,temp->val,maxi);
        return temp;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index=0;
        int mini=INT_MIN;
        int maxi=INT_MAX;
        return solve(preorder,index,mini,maxi);
    }
};