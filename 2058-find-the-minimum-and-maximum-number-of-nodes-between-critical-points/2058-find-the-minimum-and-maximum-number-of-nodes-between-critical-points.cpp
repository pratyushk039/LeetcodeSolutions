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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans(2,-1),crit;
        int i =1,mini=INT_MAX;
        while(head->next->next!=NULL){
            bool a = (head->next->val>head->next->next->val && head->next->val>head->val);
            bool b = (head->next->val<head->next->next->val && head->next->val<head->val);
            if(a||b){
                if(crit.size()>0)mini=min(mini,i-crit[crit.size()-1]);
                crit.push_back(i);
            }
            i++;
            head=head->next;
        }
        if(crit.size()<2){return ans;}
        ans[0]=mini;ans[1] = crit[crit.size()-1] - crit[0];
        return ans;
    }
};