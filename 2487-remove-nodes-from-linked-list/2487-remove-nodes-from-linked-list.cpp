/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        vector<int> v;
        while(head){
            v.push_back(head->val);
            head = head->next;
        }
        int n = v.size();
        vector<int> t(n,0);
        stack<int> s;
        s.push(0);
        for(int i=1;i<n;i++){
            while(!s.empty() && v[s.top()]<v[i]){
                t[s.top()]=1;
                s.pop();
            }
            s.push(i);
        }
        int nodes = 0;
        ListNode* hd ;
        ListNode* tl ;
        for(int i=0;i<n;i++){
            if(t[i]==0){
                if(nodes==0){
                    hd = new ListNode(v[i]);
                    tl = hd;
                    nodes=1;
                }
                else{
                    ListNode* nw = new ListNode(v[i]);
                    tl->next = nw;
                    tl = nw;
                }
            }
        }
        return hd;
    }
};