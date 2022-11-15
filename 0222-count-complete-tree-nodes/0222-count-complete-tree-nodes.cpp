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
    int height(TreeNode* root){
        if(root==NULL){return 0;}
        return 1+max(height(root->left),height(root->right));
    }
    void Last(TreeNode* root, int h,int ht,int &last){
        if(root==NULL){return ;}
        if(ht==h){last+=1;}
        Last(root->left,h,ht+1,last);
        Last(root->right,h,ht+1,last);
        return;
    }
    int countNodes(TreeNode* root) {
        if(root==NULL){return 0;}
        int h = height(root);
        int last =0;
        Last(root,h,1,last);
        return pow(2,h-1)-1+last;
    }
};