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
    unordered_map<int,set<int,greater<int>>> map;
    int dfs(TreeNode* root, int h){
        if(root == NULL){return 0;}
        map[h].insert(root->val);
        return 1+max(dfs(root->left,h+1),dfs(root->right,h+1));
        
    }
    vector<int> largestValues(TreeNode* root) {
        int h = dfs(root,0);
        vector<int> ans;
        for(int i=0;i<h;i++){
            ans.push_back(*map[i].begin());
        }
        return ans;
    }
};