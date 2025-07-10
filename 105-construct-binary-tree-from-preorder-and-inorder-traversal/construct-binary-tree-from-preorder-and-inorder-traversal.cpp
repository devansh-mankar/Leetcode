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
    int findPos(vector<int>&In,int ele)
    {
        for(int i=0;i<In.size();i++)
        {
            if(In[i]==ele)
            {return i;}
        }
        return -1;
    }
    TreeNode* solve(vector<int>&pre,vector<int>&In,int start,int end,int& index,int n)
    {
        if(index>n || start>end)
        {
            return NULL;
        }
        int element=pre[index++];
        TreeNode * curr=new TreeNode(element);
        int pos=findPos(In,element);

        curr->left=solve(pre,In,start,pos-1,index,n);
        curr->right=solve(pre,In,pos+1,end,index,n);
        return curr;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        int preIndex=0;
        return solve(preorder,inorder,0,n-1,preIndex,n);
    }
};