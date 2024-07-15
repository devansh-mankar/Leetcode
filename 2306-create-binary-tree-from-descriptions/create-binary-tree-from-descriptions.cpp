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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*>nodes;
        unordered_map<int,bool>hasParent;


        for(auto it:descriptions)
        {
            int parent=it[0];
            int child=it[1];
            bool isLeft=it[2];

            TreeNode* parentNode=NULL;
            TreeNode* childNode=NULL;

            if(nodes.find(parent)==nodes.end())
            {
                parentNode=new TreeNode(parent);
            }
            else
            {
                parentNode=nodes[parent];
            }

            if(nodes.find(child)==nodes.end())
            {
                childNode = new TreeNode(child);
            }
            else
            {
                childNode=nodes[child];
            }

            if(isLeft)
            {
                parentNode->left=childNode;
            }
            else
            {
                parentNode->right=childNode;
            }

            hasParent[child]=true;
            nodes[parent]=parentNode;
            nodes[child]=childNode;
        }

        TreeNode* root=NULL;
        for(auto it:nodes)
        {
            if(!hasParent[it.first])
            {
                root=it.second;
            }
        }

        return root;
    }
};