class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        int y=lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        int i=y-1,j=y;
        int cot=0,n=arr.size();
        while(cot<k){
            int left=INT_MAX,right=INT_MAX;
            if(i>=0){left=x-arr[i];}
            if(j<n){right=arr[j]-x;}
            if(left>right){ans.push_back(arr[j]);j+=1;}
            else if(right>left){ans.push_back(arr[i]);i-=1;}
            else if(right==left){ans.push_back(arr[i]);i-=1;}
            cot+=1;
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};