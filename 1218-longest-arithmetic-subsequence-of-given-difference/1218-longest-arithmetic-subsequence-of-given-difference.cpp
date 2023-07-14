class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        int n=arr.size();
        unordered_map<int,int> map;
        for(int i=0;i<n;i++){
            if(map.find(arr[i]-diff)==map.end()){map[arr[i]]=1;}
            else{map[arr[i]]=1+map[arr[i]-diff];}
        }
        int ans=0;
        for(auto itr:map){ans=max(ans,itr.second);}
        return ans;
    }
};