class Solution {
public:
    int solve(vector<int>&nums,int t,int maxi){
        int n=nums.size();
        int i=0,j=-1,sum=0,ans=maxi?-1:INT_MAX;
        //return max/min subaray len with sum t.
        while(i<n){
            // cout<<ans<<endl;
            if(sum<t){
                j+=1;
                if(j<n)sum+=nums[j];
                else{j=n;sum-=nums[i];i+=1;}
            }
            else if(sum==t){ans=maxi?max(ans,j-i+1):min(ans,j-i+1);sum-=nums[i];i+=1;}
            else{
                sum-=nums[i];
                i+=1;
            }
        }
        if(ans==INT_MAX){ans=-1;}
        return ans;
    }
    int minSizeSubarray(vector<int>& nums, int target) {
        int n = nums.size();
        long long sum=0;
        vector<int> nums1(2*n);
        for(int i=0;i<2*n;i++){nums1[i]=nums[i%n];}
        for(auto x:nums){sum+=x;}
        if(sum==target){return n;}
        if(sum>target){return solve(nums1,target,0);}
        
        if(target%sum==0){return n*(target/sum);}
        
        int x = solve(nums1,sum - target%sum,1);
        
        return x==-1?-1:n*(target/sum) + n-x;
        
    }
};