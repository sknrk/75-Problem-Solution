
// Given the root of a binary tree, invert the tree, and return its root.

 

// Example 1:


// Input: root = [4,2,7,1,3,6,9]
// Output: [4,7,2,9,6,3,1]
// Example 2:


// Input: root = [2,1,3]
// Output: [2,3,1]
// Example 3:

// Input: root = []
// Output: []


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
    TreeNode* invertTree(TreeNode* root) {
        swap(root);
        return root;
    }
    void swap(TreeNode* current){
        if(current==NULL){
            return;
        }
        if(current->left == NULL && current->right == NULL){
            return;
        }
        else if(current->left == NULL){
            swap(current->right);
            current -> left = current -> right;
            current -> right = NULL;
        }
        else if(current->right == NULL){
            swap(current->left);
            current -> right = current -> left;
            current -> left = NULL;
        }
        else{
            swap(current->left);
            swap(current->right);
            TreeNode* temp;
            temp = current->right;
            current->right = current->left;
            current->left = temp; 
        }
        return;
    }
};