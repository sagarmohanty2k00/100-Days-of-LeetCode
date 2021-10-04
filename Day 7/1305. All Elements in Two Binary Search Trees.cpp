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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> t1 = inorder(root1);
        vector<int> t2 = inorder(root2);
        
        vector<int> ans;
        int i=0;
        int j=0;
        
        
        while (i < t1.size() and j < t2.size()) {
            if (t1[i] < t2[j]) {
                ans.push_back(t1[i]);
                i++;
            }
            
            else{
                ans.push_back(t2[j]);
                j++;
            }
        }
        
        while (i < t1.size()) {
            ans.push_back(t1[i]);
            i++;
        }
        
        while (j < t2.size()) {
            ans.push_back(t2[j]);
            j++;
        }
        
        return ans;
    }
};