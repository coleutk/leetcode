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
    bool dfs(TreeNode* root, long long left, long long right) {
        if(!root) return true;

        if(root->val <= left || root->val >= right) {
            return false;
        }

        // Going left
        bool leftSubtree = dfs(root->left, left, root->val);

        // Going right
        bool rightSubtree = dfs(root->right, root->val, right);

        // We want to return true ONLY IF the left AND right subtrees were validated each as true
        return leftSubtree && rightSubtree;
    }

    bool isValidBST(TreeNode* root) {
        return dfs(root, LLONG_MIN, LLONG_MAX);
    }
};
