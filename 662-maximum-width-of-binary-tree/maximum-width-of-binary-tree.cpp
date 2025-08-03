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
        long long ans=0;
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});

        while(!q.empty())
        {
            int n=q.size();
            long long leftMost,rightMost;
            long long currMin=q.front().second;

            for(int i=0;i<n;i++)
            {
                auto node=q.front().first;
                long long currIndex=q.front().second-currMin;
                q.pop();

                if(i==0)
                {
                    leftMost=currIndex;
                }
                if(i==n-1)
                {
                    rightMost=currIndex;
                }

                if(node->left)
                {
                    q.push({node->left,2*currIndex+1});
                }
                if(node->right)
                {
                    q.push({node->right,2*currIndex+2});
                }
            }
            ans=max(ans,rightMost-leftMost+1);
        }
        return ans;
    }
};