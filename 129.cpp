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
    void dfs(TreeNode* root, string& path, vector<string>& paths) {
        if(root == NULL) return;

        if(root->left == NULL  && root->right == NULL) {
            path += to_string(root->val);
            paths.push_back(path);
            return;
        }

        path += to_string(root->val);
        dfs(root->left, path, paths);
        if(root->left != NULL) path.pop_back();
        dfs(root->right, path, paths);
        if(root->right != NULL) path.pop_back();
    }

    int sumNumbers(TreeNode* root) {
        vector<string> paths;
        string path = "";
        dfs(root, path, paths);

        int res = 0;
        for(auto path : paths) {
            res += stoi(path);
        }

        return res;
    }
};
