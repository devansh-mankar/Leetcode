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
            if(in[i]==element)
            {
                return i;
            }
        }
        return -1;
    }
    TreeNode* solve(vector<int>&in,vector<int>&post,int& index,int start,int end,int n)
    {
        if(index<0 || start>end)
        {
            return NULL;
        }
        int element=post[index--];
        int pos=findPos(element,in);

        TreeNode* temp=new TreeNode(element);
        temp->right=solve(in,post,index,pos+1,end,n);
        temp->left=solve(in,post,index,start,pos-1,n);
        return temp;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=postorder.size();
        int index=n-1;
        return solve(inorder,postorder,index,0,n-1,n);

    }
};