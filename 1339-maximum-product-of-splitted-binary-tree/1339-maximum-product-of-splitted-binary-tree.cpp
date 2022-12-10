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
    int dfs_sum(TreeNode* root){
        if(root==NULL){return 0;}
        return root->val=root->val+dfs_sum(root->left)+dfs_sum(root->right);
    }
    void util(TreeNode* root, int total, long long &ans){
        if(root==NULL){return;}
        if(root->left!=NULL){
            ans = max(1ll*ans,1ll*(total-root->left->val)*(root->left->val));
        }
        if(root->right!=NULL){
            ans = max(1ll*ans,1ll*(total-root->right->val)*(root->right->val));
        }
        util(root->left,total,ans);util(root->right,total,ans);
    }
    int maxProduct(TreeNode* root) {
        int total = dfs_sum(root),mod=1e9+7;
        long long ans = -LONG_LONG_MAX;
        util(root,total,ans);
        return ans%mod;
    }
};