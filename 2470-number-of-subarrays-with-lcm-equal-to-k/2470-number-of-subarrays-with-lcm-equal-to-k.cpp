#define ll long long
class Solution {
public:
    ll gcd(int a,int b){
        if(b==0){return a;}
        return gcd(b,a%b);
    }
    ll lcm (int a,int b){
        return (1ll*a*b)/gcd(a,b);
    }
    int subarrayLCM(vector<int>& nums, int k) {
        int n = nums.size(),ans=0;
        
        for(int i=0;i<n;i++){
            int l = nums[i];//if(nums[i]==k){ans+=1;}
            for(int j=i;j<n;j++){
                l = lcm(l,nums[j]);
                if(l==k){ans+=1;}
                //else{break;}
            }
        }
        return ans;
    }
};