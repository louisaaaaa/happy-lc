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
        vector<double> averageOfLevels(TreeNode* root) {
            queue<TreeNode *> nodes;
            nodes.push(root);
            vector<double> res;
            while(!nodes.empty()){
                double n = nodes.size();
                double sum = 0;
                for (int i=0;i<n;i++){
                    TreeNode* node = nodes.front();
                    nodes.pop();
                    sum += node->val;
                    if(node->left) nodes.push(node->left);
                    if(node->right) nodes.push(node->right);
                }
                res.push_back(sum/n);
            }
    
            return res;
            
        }
    };