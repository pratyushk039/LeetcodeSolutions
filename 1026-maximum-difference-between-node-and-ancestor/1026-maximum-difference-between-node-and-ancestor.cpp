#define pb push_back
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
    int ans;
    Solution(){
        ans= -INT_MAX;
    }
    void dfs(TreeNode* root,vector<int>&v){
        if(root==NULL){return;}
        if(v.size()==0){v.pb(root->val);dfs(root->left,v);dfs(root->right,v);return;}
        int x = root->val;
        for(int i:v){
            ans =max(ans,abs(i-x));
        }
        v.pb(x);
        dfs(root->left,v);dfs(root->right,v);
        v.pop_back();
    }
    int maxAncestorDiff(TreeNode* root) {
        vector<int> v;
        dfs(root,v);
        return ans;
    }
};