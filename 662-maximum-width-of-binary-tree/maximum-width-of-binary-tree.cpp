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
    long long solve(TreeNode* root,int l,long long i,unordered_map<int,long long>&mp)
    {
        if(root==NULL)
        {
            return 0;
        }
        if(mp.find(l)==mp.end())
        {
            mp[l]=i;
        }
        long long normalizedIndex=i-mp[l];
        long long left=solve(root->left,l+1,2*normalizedIndex,mp);
        long long right=solve(root->right,l+1,2*normalizedIndex+1,mp);
        return max(max(left,right),i-mp[l]+1);
    }
    int widthOfBinaryTree(TreeNode* root) {
        unordered_map<int,long long>mp;
       return solve(root,0,0,mp);
        
    }
};