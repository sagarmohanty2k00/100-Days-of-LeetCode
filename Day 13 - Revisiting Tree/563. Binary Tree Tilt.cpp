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
    int helper(TreeNode* root, int& sum) {
        if (root == NULL) return 0;
        
        int lt = helper(root->left, sum);
        int rt = helper(root->right, sum);
        
        sum += abs(lt - rt);
        return lt + rt + root->val;
    }
    
    int findTilt(TreeNode* root) {
        int sum = 0;
        int rv = helper(root, sum);
        
        return sum;
    }
};