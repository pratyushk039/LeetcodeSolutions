class Solution {
public:
    int halveArray(vector<int>& piles) {
        double sum=0,rem=0;
        int ans=0;
        priority_queue<double>pq;
        for(int i:piles){sum+=i;pq.push(i);}
        while(rem<sum/2){
            double x = pq.top();
            pq.pop();
            rem+=x/2;
            pq.push(x/2);
            ans+=1;
        }
        return ans;
    }
};