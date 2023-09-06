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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n=0;
        auto lnh=head;
        vector<ListNode*> ans;
        while(lnh!=NULL){n+=1;lnh=lnh->next;}
        lnh=head;
        if(k>=n){
            for(int i=0;i<k;i++){auto lnh2=(lnh==NULL)?lnh:new ListNode(lnh->val);ans.push_back(lnh2);if(lnh!=NULL)lnh=lnh->next;}
            return ans;
        }
        
        int len=n/k + 1,m=n%k,x=0;
        auto itr=head;
        while(ans.size()<k){
            x++;
            int l;
            if(ans.size()>=m){l=len-1;}else{l=len;}
            auto h1 = new ListNode();
            auto t1=h1;
            for(int j=0;j<l;j++){
                t1->next = new ListNode(itr->val);
                t1=t1->next;
                if(itr->next!=NULL)itr=itr->next;
            }
            ans.push_back(h1->next);
            
        }
        return ans;
    }
};