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
#define vi vector<int>
class Solution {
public:
    void dfs(unordered_map<int,vi>&map,TreeNode* root,int height){
        if(root==NULL){return ;}
        map[height].push_back(root->val);
        dfs(map,root->left,height+1);
        dfs(map,root->right,height+1);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        unordered_map<int,vi> map;
        dfs(map,root,0);
        int h=-1; for(auto itr:map){h=max(h,itr.first);}
        vector<vi> ans(h+1);
        bool rev=false;
        for(int i=0;i<=h;i++){
            auto vec = map[i];
            if(rev){
                reverse(vec.begin(),vec.end());
            }
            ans[i]=vec;
            rev=!rev;
        }
        return ans;
    }
};