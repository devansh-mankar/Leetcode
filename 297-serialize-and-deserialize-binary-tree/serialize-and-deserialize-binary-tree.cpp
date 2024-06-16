class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string s= "";
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* curNode= q.front();
            q.pop();

            if(curNode==NULL) s.append("#,");
           else s.append(to_string(curNode->val)+',');
           if(curNode != NULL){
               q.push(curNode->left);
               q.push(curNode->right);            
           }
        }

        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;

        stringstream s(data);
        string str;

        getline(s,str, ',');

        queue<TreeNode*> q;

        TreeNode* root= new TreeNode(stoi(str));
        q.push(root);


        while(!q.empty()){
            TreeNode* node= q.front();
            q.pop();

            getline(s,str,',');
            if(str=="#"){
                node->left= NULL;
            }
            else{
                TreeNode* lnode= new TreeNode(stoi(str));
                node->left= lnode;
                q.push(lnode);
            }

            getline(s,str, ',');
            if(str=="#"){
                node->right= NULL;
            }
            else{
                TreeNode* rnode= new TreeNode(stoi(str));
                node->right= rnode;
                q.push(rnode);
            }
        }
        return root; 
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));