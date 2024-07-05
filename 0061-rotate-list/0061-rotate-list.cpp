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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k==0)return head;
        vector<ListNode*> v;
        v.push_back(head);
        ListNode* start = head;
        while(head->next!=NULL){
            head=head->next;
            v.push_back(head);
        }
        int n = v.size();
        k = k%n;
        if(k==0)return start;
        v[n-k-1]->next=NULL;
        v[n-1]->next = v[0];
        return v[n-k];
    }
};