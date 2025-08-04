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
    void solve(TreeNode* root,vector<int>&in)
    {
        if(!root) return ;

        solve(root->left,in);
        in.push_back(root->val);
        solve(root->right,in);
    }
    TreeNode* build(TreeNode* root,vector<int>&in,int start,int end)
    {
        if(start>end)
        {
            return NULL;
        }
        int mid=start+(end-start)/2;
        TreeNode* temp=new TreeNode(in[mid]);
        temp->left=build(root,in,start,mid-1);
        temp->right=build(root,in,mid+1,end);
        return temp;
    }
    TreeNode* balanceBST(TreeNode* root) {
        if(root==NULL)
        {
            return NULL;
        }
        vector<int>in;
        solve(root,in);
        int n=in.size();
        return build(root,in,0,n-1);
    }
};