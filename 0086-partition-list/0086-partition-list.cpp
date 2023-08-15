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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL){return head;}
        vector<int> v;
        ListNode* itr = head;
        while(itr!=NULL){if(itr->val<x){v.push_back(itr->val);}itr = itr->next;}
        itr = head;
        while(itr!=NULL){if(itr->val>=x){v.push_back(itr->val);}itr = itr->next;}
        ListNode* head1 = new ListNode(v[0]);
        ListNode* tail = head1;
        for(int i=1;i<v.size();i++){
            ListNode* temp = new ListNode(v[i]);
            tail->next = temp;
            tail=temp;
        }
        return head1;
    }
};