
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==NULL)
        {
            return ans;
        }
        TreeNode* curr=root;
        while(curr)
        {
            if(curr->left==NULL)
            {
                ans.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode* pred=curr->left;
                while(pred->right && pred->right!=curr)
                {
                    pred=pred->right;
                }
                if(pred->right==NULL)
                {
                    pred->right=curr;
                    ans.push_back(curr->val);
                    curr=curr->left;
                }
                else{
                    pred->right=NULL;
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
};