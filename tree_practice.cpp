using namespace std;
#include <iostream>

struct TreeNode{
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode(): val(0), left(nullptr), right(nullptr){}
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(nullptr), right(nullptr){}
};


//binary search tree, if smaller go left, if larger go right
TreeNode* addNode(TreeNode* root, int val){
    if (root==nullptr){
        return new TreeNode(val); 
    }
    if (val < root->val){
        if (root->left==nullptr){
            root->left = new TreeNode(val);
        } else{
            root->left = addNode(root->left, val);
        }
    } else if (val > root->val) {
        if (root->right == nullptr){
            root->right = new TreeNode(val);
        } else{
            root->right = addNode(root->right, val);
        }
    } 
    return root;
}

TreeNode* deleteNode(TreeNode* root, int val){
    if (root == nullptr) return root;

    if (val < root->val){ //这里不能是小于等于！！！
        root->left = deleteNode(root->left, val);
    } else if (val > root->val){
        root->right = deleteNode(root->right, val);
    } else{ // found node to delete
        if (root->left == nullptr && root->right == nullptr){
            delete root;
            return nullptr;
        } else if (root->left == nullptr){ // 注意这里左边是null所以要保留右边的孩子
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr){
            TreeNode* temp = root->left;
            delete root;
            return temp;
        } else{ // both child exist
            // 要找succesor
            TreeNode * succesor = root->right; // find smallest in right
            while (succesor->left != nullptr){
                succesor = succesor->left;
            }
            root->val = succesor->val;
            root->right = deleteNode(root->right, succesor->val);
        }
    }
    return root;
}

void printTree(TreeNode * root){
    if (root==nullptr) return;
    printTree(root->left);
    cout << root->val << " ";
    printTree(root->right);
}


int main(){
    TreeNode* root = nullptr;

    root = addNode(root, 2);
    root = addNode(root, 5);
    root = addNode(root, 1);
    root = addNode(root, 10);
    root = addNode(root, 2);
    printTree(root);
    cout << "\n";
    addNode(root, 8);
    // root = deleteNode(root, 10);
    // root = deleteNode(root, 8);
    // root = deleteNode(root, 3);
    printTree(root);
}