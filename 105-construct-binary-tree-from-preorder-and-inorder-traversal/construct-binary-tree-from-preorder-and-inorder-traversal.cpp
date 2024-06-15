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
    int findPosition(int element,vector<int>&in)
    {
        int n=in.size();

        for(int i=0;i<n;i++)
        {
            if(in[i]==element)
            {
                return i;
            }
        }
        return -1;
    }
    TreeNode* solve(vector<int>&pre,vector<int>&in,int& index,int Instart,int Inend,int n)
    {
        if(Instart>Inend || index>n)
        {
            return NULL;
        }
        int element=pre[index++];
        TreeNode* temp=new TreeNode(element);
        int pos=findPosition(element,in);

        temp->left=solve(pre,in,index,Instart,pos-1,n);
        temp->right=solve(pre,in,index,pos+1,Inend,n);

        return temp;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        int preIndex=0;
        return solve(preorder,inorder,preIndex,0,n-1,n);
    }
};