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
        vector<int> rightSideView(TreeNode* root) {
            // level traverse
            vector<int> res;
            if (root == nullptr){
                return res;
            }
            queue<TreeNode*> my_q;
            my_q.push(root);
            // res.push_back(root->val);
    
            while(!my_q.empty()){
                int level_size = my_q.size();
                for (int i=0;i<level_size;i++){
                    TreeNode* node = my_q.front();
                    my_q.pop();
                    if (i==level_size-1){
                        res.push_back(node->val);
                    }
                    if (node->left != nullptr){
                        my_q.push(node->left);
                    }
                    if (node->right != nullptr){
                        my_q.push(node->right);
                    }
                }
            }
            return res;
    
        }
    };