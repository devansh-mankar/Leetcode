class Solution {
public:
    void createMapping(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& nodeToParent) {
        if (root == NULL) return;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            
            if (node->left) {
                q.push(node->left);
                nodeToParent[node->left] = node;
            }
            if (node->right) {
                q.push(node->right);
                nodeToParent[node->right] = node;
            }
        }
    }
    
    // FIXED: Proper way to find the start node
    TreeNode* findStartNode(TreeNode* root, int start) {
        if (!root) return nullptr;
        if (root->val == start) return root;
        
        TreeNode* left = findStartNode(root->left, start);
        if (left) return left;
        
        return findStartNode(root->right, start);
    }
    
    int solve(int start, unordered_map<TreeNode*, TreeNode*>& nodeToParent, TreeNode* root) {
        // FIXED: Proper node finding
        TreeNode* temp = findStartNode(root, start);
        if (!temp) return 0;  // Start node not found
        
        int time = 0;
        queue<TreeNode*> q;
        q.push(temp);
        unordered_map<TreeNode*, bool> vis;
        vis[temp] = true;
        
        while (!q.empty()) {
            int n = q.size();
            bool flag = false;
            
            while (n--) {
                auto node = q.front();
                q.pop();
                
                // Check left child
                if (node->left && !vis[node->left]) {
                    flag = true;
                    q.push(node->left);
                    vis[node->left] = true;
                }
                
                // Check right child
                if (node->right && !vis[node->right]) {
                    flag = true;
                    q.push(node->right);
                    vis[node->right] = true;
                }
                
                // Check parent - FIXED: Added = true
                if (nodeToParent[node] && !vis[nodeToParent[node]]) {
                    flag = true;
                    q.push(nodeToParent[node]);
                    vis[nodeToParent[node]] = true;  // FIXED!
                }
            }
            
            if (flag) {
                time++;
            }
        }
        return time;
    }
    
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> nodeToParent;
        createMapping(root, nodeToParent);
        return solve(start, nodeToParent, root);
    }
};

// Alternative: Cleaner single-pass solution
class SolutionOptimized {
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> nodeToParent;
        TreeNode* startNode = nullptr;
        
        // Single BFS to build parent map AND find start node
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            
            if (node->val == start) {
                startNode = node;
            }
            
            if (node->left) {
                q.push(node->left);
                nodeToParent[node->left] = node;
            }
            if (node->right) {
                q.push(node->right);
                nodeToParent[node->right] = node;
            }
        }
        
        // BFS from start node
        int time = 0;
        q.push(startNode);
        unordered_map<TreeNode*, bool> vis;
        vis[startNode] = true;
        
        while (!q.empty()) {
            int n = q.size();
            bool flag = false;
            
            while (n--) {
                auto node = q.front();
                q.pop();
                
                // Check all three directions
                vector<TreeNode*> neighbors = {node->left, node->right, nodeToParent[node]};
                
                for (auto neighbor : neighbors) {
                    if (neighbor && !vis[neighbor]) {
                        flag = true;
                        q.push(neighbor);
                        vis[neighbor] = true;
                    }
                }
            }
            
            if (flag) time++;
        }
        
        return time;
    }
};