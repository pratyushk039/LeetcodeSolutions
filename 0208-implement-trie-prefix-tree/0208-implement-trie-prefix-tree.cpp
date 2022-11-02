class TrieNode{
    public:
    vector<TrieNode*> children;
    bool end = false;
    TrieNode(){
        children.resize(26,NULL);
    }
};
class Trie {
public:
    TrieNode* root;
    Trie() {
        this->root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* par = root;
        for(auto ch:word){
            int c = ch-'a';
            if(par->children[c]==NULL){par->children[c]=new TrieNode();}
            par = par->children[c];
            
        }
        par->end=true;
        return;
    }
    
    bool search(string word) {
        TrieNode* par = root;
        for(auto ch:word){
            int c = ch-'a';
            if(par->children[c]==NULL){return false;}
            par = par->children[c];
        }
        return par->end;
    }
    
    bool startsWith(string prefix) {
        TrieNode* par = root;
        for(auto ch:prefix){
            int c = ch-'a';
            if(par->children[c]==NULL){return false;}
            par = par->children[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */