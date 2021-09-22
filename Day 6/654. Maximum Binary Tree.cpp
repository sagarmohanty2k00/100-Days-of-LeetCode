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
    TreeNode* helper(const vector<int> nums, const int start, const int end) {
        if (start > end) return NULL;
        
        int item = start;
        for (int i=start; i<=end; i++) {
            if (nums[i] > nums[item]) item = i;
        }
        
        TreeNode* head = new TreeNode(nums[item]);
        head->left = helper(nums, start, item-1);
        head->right =  helper(nums, item+1, end);
        
        return head;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        return helper(nums, 0, nums.size()-1);
    }
};