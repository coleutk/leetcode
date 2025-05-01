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
    void dfs(TreeNode* root, int &target, int parentVal, int &parent, int depth, int &currDepth) {
        if(!root) return;

        if(root->val == target) {
            parent = parentVal;
            currDepth = depth;
            return;
        }

        dfs(root->left, target, root->val, parent, depth + 1, currDepth);
        dfs(root->right, target, root->val, parent, depth + 1, currDepth);
    }

    bool isCousins(TreeNode* root, int x, int y) {
        int parent1 = -1, parent2 = -1;
        int depth1 = -1, depth2 = -1;
        dfs(root, x, -1, parent1, 0, depth1);
        dfs(root, y, -1, parent2, 0, depth2);
        
        return parent1 != parent2 && depth1 == depth2;
    }
};
