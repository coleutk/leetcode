class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
        // Create a queue to store the level associated with the
        // current node 
        queue<pair<int, TreeNode *>> q;
        
        // Create a vector to store the results by level 
        vector<vector<int>> res; 

        // It is better to perform this initial check here instead of
        // during the BFS
        if(root) {
            q.push({0, root});
        } else {
            return {};
        } 

        vector<int> curr;
        while(!q.empty()) {
            auto pair = q.front();
            q.pop();

            int level = pair.first;
            TreeNode* node = pair.second;

            // If the current level associated with the node we just
            // popped from the queue is GREATER than the current amount
            // of levels we have stored, we know to add our current
            // iteration of curr to res and start anew
            if(level > res.size()) {
                res.push_back(curr);
                curr.clear();
            }

            curr.push_back(node->val);
            
            // Push the current node's left and right child with the
            // appropriate level
            if(node->left) {
                q.push({level + 1, node->left});
            } 

            if(node->right) {
                q.push({level + 1, node->right}); 
            }
        }	
         
        // Push back the remaining curr vector because although we
        // have finished, our if condition that is usually triggered
        // to add curr to res will not activate for the very last
        // iteration of curr
        res.push_back(curr);
        return res;
	}	
};
