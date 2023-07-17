// Given a binary tree, determine if it is 
// height-balanced
// .

 

// Example 1:


// Input: root = [3,9,20,null,null,15,7]
// Output: true
// Example 2:


// Input: root = [1,2,2,3,3,null,null,4,4]
// Output: false
// Example 3:

// Input: root = []
// Output: true
 

// Constraints:

// The number of nodes in the tree is in the range [0, 5000].
// -104 <= Node.val <= 104


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
bool globalVariable = 0;
class Solution {
public:
    int checkBalance(TreeNode* current,int depth){
        int leftTree=0,rightTree=0;
        if(!current){
            globalVariable = 0;
            return depth;
        }
        if(current->right==NULL && current->left==NULL){
            return depth;
        }
        if(current->right!=NULL){
            rightTree = checkBalance(current->right,depth+1);
        }
        else{
            rightTree = depth;
        }
        if(current->left!=NULL){
            leftTree = checkBalance(current->left,depth+1);
        }
        else{
            leftTree = depth;
        }
        if(abs(leftTree-rightTree)>1){
            globalVariable=1;
        }
        return max(leftTree,rightTree);
    }
    bool isBalanced(TreeNode* root) {
        globalVariable = 0;
        checkBalance(root,0);
        if(globalVariable==1){
            return false;
        }
        else{
            return true;
        }
    }
};


// Used depth variable to check depth for every node. Compared them in parent node. If it is not balanced globalVariable value changed to 1.  