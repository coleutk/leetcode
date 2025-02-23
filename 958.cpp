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
    bool isCompleteTree(TreeNode* root) {
        vector<vector<int>> levels;
        queue<TreeNode*> q;
        q.push(root);
        int lastLevel = -1;
        int cnt = -1;
        int lastValAdded = -1;

        while(!q.empty()) {
            cnt++;
            int size = q.size();
            vector<int> currLevel;

            for(int i = 0; i < size; i++) {
                // Add each of the node's children to the level
                TreeNode* curr = q.front();
                q.pop();

                if(!curr) {
                    currLevel.push_back(-1);
                } else {
                    // We have a valid node so add its value to the currLevel
                    // and its children to the queue for next go around
                    lastLevel = cnt;
                    lastValAdded = curr->val;
                    currLevel.push_back(curr->val);
                    q.push(curr->left);
                    q.push(curr->right);
                }
            }

            levels.push_back(currLevel);
        }

        int lastValSeen = -1;
        for(int i = 0; i < levels.size() - 1; i++) {
            for(int j = 0; j < levels[i].size(); j++) {
                if(i < lastLevel) {
                    if(levels[i][j] == -1) return false;
                } else {
                    // We are on the last level, so we just need to check if we see a -1
                    // before we have seen the lastAdded value
                    if(levels[i][j] != -1) {
                        lastValSeen = levels[i][j];
                    } else {
                        // We have encountered a -1, so check if we have seen the last value yet
                        if(lastValSeen < lastValAdded) return false;
                    }
                    
                }
            }
        }
        return true;
    }
};
