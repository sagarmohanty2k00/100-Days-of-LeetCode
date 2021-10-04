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
    vector<int> inorder(TreeNode* root) {
        stack<TreeNode*> s;
        s.push(root);
        unordered_set<TreeNode*> visited;
        
        vector<int> v;
        
        while (!s.empty()) {
            TreeNode* node = s.top();
            s.pop();
            
            if (visited.find(node) != visited.end()) {
                v.push_back(node->val);
            }
            else if(node != NULL) {
                visited.insert(node);
                s.push(node->right);
                s.push(node);
                s.push(node->left);
            }
        }
        
        return v;
    }
    
    TreeNode* buildTree(const vector<int> nodes, const int start, const int end) {
        if (start > end) return NULL;
        
        int m = (start + end)/2;
        TreeNode* node = new TreeNode(nodes[m]);
        
        node->left = buildTree(nodes, start, m-1);
        node->right = buildTree(nodes, m+1, end);
        
        return node;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> in = inorder(root);
        return buildTree(in, 0, in.size()-1);
    }
};