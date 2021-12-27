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
    bool isCousins(TreeNode* root, int x, int y) {
        if(root == NULL) {
            return false;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        unordered_map<TreeNode*, TreeNode*> parent;
        
        while(!q.empty()) {
            TreeNode* foundA = NULL;
            TreeNode* foundB = NULL;
            
            int n = q.size();
            for (int i=0; i<n; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                if (node->val == x) foundA = node;
                if (node->val == y) foundB = node;
                
                if (node->left != NULL) {
                    parent[node->left] = node;
                    q.push(node->left);
                }
                if (node->right != NULL) {
                    parent[node->right] = node;
                    q.push(node->right);
                }
            }
            
            
            if (foundA != NULL and foundB != NULL and foundA != foundB and parent[foundA] != parent[foundB]) return true;
        }
        
        return false;
    }
};