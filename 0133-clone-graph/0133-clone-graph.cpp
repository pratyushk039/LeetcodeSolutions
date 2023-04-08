/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*> o2n;
    unordered_map<Node*,bool> vis,vis2;
    void dfs1(Node* orig){
        Node* new_node = new Node(orig->val);
        o2n[orig] = new_node;
        vis[orig] = true;
        for(auto nbr:orig->neighbors){
            if(vis[nbr]==false){dfs1(nbr);}
        }
    }
    void dfs2(Node* orig){
        vis2[orig]=true;
        for(auto nbrs:orig->neighbors){
            o2n[orig]->neighbors.push_back(o2n[nbrs]);
            if(vis2[nbrs]==false){
                dfs2(nbrs);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL){return NULL;}
        dfs1(node);
        dfs2(node);
        return o2n[node];
    }
};