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
    bool checkSym(TreeNode* L,TreeNode* R){
        if(L==NULL && R==NULL){
            return true;
        }
        if(L==NULL || R==NULL){
            return false;
        }
        return (L->val == R->val) && checkSym(L->left,R->right) && checkSym(L->right,R->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return checkSym(root->left,root->right);
    }
};