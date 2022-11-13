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
int minSwaps(vector<int>arr)
{
    int N=arr.size();
  int ans = 0;
  vector<int>temp = arr;
  map <int, int> h;
 
  sort(temp.begin(), temp.end());
  for (int i = 0; i < N; i++)
  {
    h[arr[i]] = i;
  }
  for (int i = 0; i < N; i++)
  {
    if (arr[i] != temp[i])
    {
      ans++;
      int init = arr[i];
      swap(arr[i], arr[h[temp[i]]]);
      h[init] = h[temp[i]];
      h[temp[i]] = i;
    }
  }
  return ans;
}
    int height(TreeNode* root){
        if(root==NULL){return 0;}
        return 1+max(height(root->left),height(root->right));
    }
    void fill(TreeNode* root,vector<vector<int>> &levels,int h){
        if(root==NULL){return;}
        if(root->left!=NULL){levels[h+1].push_back(root->left->val);}
        if(root->right!=NULL){levels[h+1].push_back(root->right->val);}
        fill(root->left,levels,h+1);
        fill(root->right,levels,h+1);
        return;
    }
    int minimumOperations(TreeNode* root) {        
        int max_h=height(root);
        vector<vector<int>> levels(max_h+1);
        levels[0].push_back(root->val);
        fill(root,levels,0);
        int ans=0;
        for(auto v:levels){
            //for(int i:v){cout<<i<<" ";}
            //cout<<endl;
            ans+=minSwaps(v);
        }
        return ans;
    }
};