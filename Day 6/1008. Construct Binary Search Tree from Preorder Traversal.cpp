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
    TreeNode* construct(const vector<int> preorder, const int start, const int end) {
        if (start > end) return NULL;
        
        TreeNode* node = new TreeNode(preorder[start]);
        
        if (start == end) return node;
        
        int rci = -1;
        for (int i=start+1; i<=end; i++) {
            if (preorder[i] > preorder[start]) {
                rci = i;
                break;
            }
        }
        
        if (rci != -1) {
            node->left  = construct(preorder, start+1, rci-1);
            node->right = construct(preorder, rci, end);
        }
        
        else {
            node->left = construct(preorder, start+1, end);
        }
        
        
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        return construct(preorder, 0, n-1);
    }
};