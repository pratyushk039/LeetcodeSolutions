class Solution {
public:
    int gcd(int a,int b){
        if(b==0){return a;}
        return gcd(b,a%b);
    }
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int g=numsDivide[0];
        int n=numsDivide.size(),n1=nums.size();
        for(int i=1;i<n;i++){
            g=gcd(g,numsDivide[i]);
        }
        map<int,int>m;
        for(int i=0;i<n1;i++){m[nums[i]]+=1;}
        int ans=0;
        for(auto itr:m){
            if(itr.first!=0 && g%itr.first==0){break;}
            else if(itr.first==0 || g%itr.first!=0){ans+=itr.second;}
        }
        return ans==n1?-1:ans;
    }
};