class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        return a[0]<b[0];
    }
    int maximumBeauty(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>> arr(n);
        for(int i=0;i<n;i++){
            arr[i] = {nums[i]-k,nums[i]+k};
        }
        sort(arr.begin(),arr.end(),comp);
        int ans=0,streak,start=0,i=1;
        while(i<n){
            int mini = arr[start][1];
            if(arr[i][0]<=mini){streak=i-start+1;mini=min(mini,arr[i][1]);ans=max(ans,streak);i++;continue;}
            else{start+=1;streak--;}
            
        }
        //for(int i=0;i<n;i++){cout<<arr[i][0]<<" "<<arr[i][1]<<endl;}
        return max(ans,1);
    }
};