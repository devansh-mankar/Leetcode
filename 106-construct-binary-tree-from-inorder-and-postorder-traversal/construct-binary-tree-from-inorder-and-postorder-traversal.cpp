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
    TreeNode* solve(vector<int>&post,unordered_map<int,int>&mp,int& index,int start,int end)
    {
        if(start>end || index<0)
        {
            return NULL;
        }
        int element=post[index--];
        int pos=mp[element];

        TreeNode* curr=new TreeNode(element);
         curr->right=solve(post,mp,index,pos+1,end);
        curr->left=solve(post,mp,index,start,pos-1);
       
        return curr;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        int n=inorder.size();
        int index=n-1;
        return solve(postorder,mp,index,0,n-1);
    }
};