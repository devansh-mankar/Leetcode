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
    TreeNode* solve(vector<int>&pre,vector<int>&in,int& index,unordered_map<int,int>&mp,int start,int end,int n)
    {
        if(start>end || index>n)
        {
            return NULL;
        }
        int element=pre[index++];
        int pos=mp[element];

        TreeNode* curr=new TreeNode(element);

        curr->left=solve(pre,in,index,mp,start,pos-1,n);
        curr->right=solve(pre,in,index,mp,pos+1,end,n);
        return curr;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        int index=0;
        return solve(preorder,inorder,index,mp,0,preorder.size()-1,preorder.size());
    }
};