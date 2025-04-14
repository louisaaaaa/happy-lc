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


 /*
 最简单想法先层序遍历再反转
 */
class Solution {
    public:
        vector<vector<int>> levelOrderBottom(TreeNode* root) {
            vector<vector<int>> res;
            if (root == nullptr){
                return res;
            }
            queue<TreeNode*> nodes;
            nodes.push(root);
            
    
            while(!nodes.empty()){
                int len = nodes.size();
                vector<int> level;
                for (int i=0;i<len;i++){
                    TreeNode *node = nodes.front();
                    nodes.pop();
                    level.push_back(node->val);
                    if (node->left != nullptr) nodes.push(node->left);
                    if (node->right != nullptr) nodes.push(node->right);
                }
                res.push_back(level);
            }
    
            reverse(res.begin(),res.end());
            return res;
        }
    };