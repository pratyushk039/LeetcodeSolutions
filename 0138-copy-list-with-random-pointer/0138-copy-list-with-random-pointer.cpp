/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){return NULL;}
        unordered_map<Node*,Node*> map;
        Node* new_head = new Node(head->val);
        Node* tail=new_head,*itr=head->next;
        map[head]=new_head;
        while(itr!=NULL){
            Node* new_node= new Node(itr->val);
            tail->next=new_node;tail=new_node;
            map[itr]=new_node;
            itr=itr->next;
        }
        Node* itr2=head;
        while(itr2!=NULL){
            if(itr2->random==NULL){map[itr2]->random=NULL;}
            else{
                map[itr2]->random = map[itr2->random];
            }
            itr2=itr2->next;
        }
        return new_head;
    }
};