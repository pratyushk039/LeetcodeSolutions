/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*,int> map;
        int d=0;
        while(head!=NULL){
            if(map.find(head)!=map.end()){return head;}
            map[head]=d;
            d+=1;
            head=head->next;
        }
        return NULL;
    }
};