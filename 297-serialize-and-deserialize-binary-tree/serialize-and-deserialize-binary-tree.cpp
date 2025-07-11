/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string s="";
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            auto node=q.front();
            q.pop();

            if(node==NULL) s.append("#,");
            else s.append(to_string(node->val)+',');

            if(node)
            {
                q.push(node->left);
            }
            if(node)
            {
                q.push(node->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;

        stringstream s(data);
        string str;
        getline(s,str,',');

        queue<TreeNode*>q;
        TreeNode* root=new TreeNode(stoi(str));

        q.push(root);
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();

            getline(s,str,',');
            if(str=="#")
            {
                node->left=NULL;
            }
            else{
                TreeNode* lnode=new TreeNode(stoi(str));
                node->left=lnode;
                q.push(lnode);
            }

            getline(s,str,',');
            if(str=="#")
            {
                node->right=NULL;
            }
            else{
                TreeNode* rnode=new TreeNode(stoi(str));
                node->right=rnode;
                q.push(rnode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));