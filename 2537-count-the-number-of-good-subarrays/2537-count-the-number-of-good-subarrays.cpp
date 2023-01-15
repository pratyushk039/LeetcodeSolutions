class Solution {
public:
    long long nc2(int n){
        long long x=1ll*n*(n-1)/2;
        return x;
    }
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int,int>map;
        long long ans=0;
        int i=0,j=0,n=nums.size(),freq=0;
        bool first=true;
        while(j<n && i<=j){
            //cout<<freq<<endl;
            if(freq>=k){
                ans+=n-j;
                freq-=nc2(map[nums[i]]);
                map[nums[i]]-=1;
                freq+=nc2(map[nums[i]]);
                i+=1;
            }
            else{
                if(j==0 && first){j=-1;first=false;}
                j+=1;
                freq-=nc2(map[nums[j]]);
                map[nums[j]]+=1;
                freq+=nc2(map[nums[j]]);
            }
        }
        return ans;
    }
};