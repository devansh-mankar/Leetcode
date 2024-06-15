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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
       long long int ans=0;
        queue<pair<TreeNode*,long long int>>q;
        q.push({root,0});

        while(!q.empty())
        {
           long long int n=q.size();
           long long int leftmost,rightmost;
           long long  int currMin=q.front().second;

            for(int i=0;i<n;i++)
            {
                TreeNode* temp=q.front().first;
               long long int currIndex=q.front().second-currMin;
                q.pop();
                
                if(i==0)
                {
                    leftmost=currIndex;
                }
                if(i==n-1)
                {
                    rightmost=currIndex;
                }

                if(temp->left)
                {
                    q.push({temp->left,currIndex*2+1});
                }
                if(temp->right)
                {
                    q.push({temp->right,currIndex*2+2});
                }
            }
            ans=max(ans,(rightmost-leftmost+1));
        }
        return ans;
    }
};