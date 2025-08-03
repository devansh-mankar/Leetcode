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
    int findPos(int element,vector<int>&in)
    {
        for(int i=0;i<in.size();i++)
        {
            if(element==in[i])
            {
                return i;
            }
        }
        return -1;
    }
    TreeNode* solve(vector<int>&pre,vector<int>&in,int& index,int start,int end,int n)
    {
        if(start>end || index>n)
        {
            return NULL;
        }
        int element=pre[index++];
        int pos=findPos(element,in);

        TreeNode* temp=new TreeNode(element);
        temp->left=solve(pre,in,index,start,pos-1,n);
        temp->right=solve(pre,in,index,pos+1,end,n);
        return temp;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index=0;
        int n=preorder.size();
        return solve(preorder,inorder,index,0,n-1,n);
    }
};