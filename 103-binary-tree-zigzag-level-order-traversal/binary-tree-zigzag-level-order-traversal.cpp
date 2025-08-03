
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)
        {
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            int n=q.size();
            vector<int>temp;
            while(n--)
            {
                auto node=q.front();
                q.pop();

                temp.push_back(node->val);
                if(node->left)
                {
                    q.push(node->left);
                }
                if(node->right)
                {
                    q.push(node->right);
                }
            }
            ans.push_back(temp);
        }

        int n=ans.size();
        for(int i=0;i<n;i++)
        {
            if(i%2!=0)
            {
                reverse(ans[i].begin(),ans[i].end());
            }
        }
        return ans;
    }
};