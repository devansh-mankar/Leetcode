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
        if(index<0 || start>end)
        {
            return NULL;
        }
        int element=post[index--];
        int pos=mp[element];

        TreeNode* temp=new TreeNode(element);
         temp->right=solve(post,mp,index,pos+1,end);
        temp->left=solve(post,mp,index,start,pos-1);
       
        return temp;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mp;
        int n=inorder.size();
        for(int i=0;i<n;i++)
        {
            mp[inorder[i]]=i;
        }
        int index=n-1;
        return solve(postorder,mp,index,0,n-1);
    }
};