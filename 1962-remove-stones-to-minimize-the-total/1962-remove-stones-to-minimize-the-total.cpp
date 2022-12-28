class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int sum=0,rem=0;
        priority_queue<int>pq;
        for(int i:piles){sum+=i;pq.push(i);}
        for(int i=0;i<k;i++){
            int x = pq.top();
            pq.pop();
            rem+=x/2;
            x%2==0?pq.push(x/2):pq.push(x/2+1);
            if(pq.top()==0){break;}
        }
        return sum-rem;
    }
};