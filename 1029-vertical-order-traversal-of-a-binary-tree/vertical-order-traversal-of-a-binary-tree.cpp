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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)
        {
            return ans;
        }
        map<int,map<int,multiset<int>>>nodes;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});

        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            int hd=it.second.first;
            int lvl=it.second.second;
            nodes[hd][lvl].insert(it.first->val);

            if(it.first->left)
            {
                q.push({it.first->left,{hd-1,lvl+1}});
            }
            if(it.first->right)
            {
                q.push({it.first->right,{hd+1,lvl+1}});
            }
        }

        for(auto it:nodes)
        {
            vector<int>temp;
            for(auto j:it.second)
            {
                temp.insert(temp.end(),j.second.begin(),j.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};