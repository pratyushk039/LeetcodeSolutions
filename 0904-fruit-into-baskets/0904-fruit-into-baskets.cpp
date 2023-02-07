class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size(),ans=0,idx=0,prev=0;
        unordered_map<int,int> map;
        map[fruits[0]]=1;
        if(n==1){return 1;}
        for(int i=1;i<n;i++){
            map[fruits[i]]+=1;
            if(map.size()>2){
                //reduce frequency from 3 to 2 , after calculating ans.
                ans=max(i-prev,ans);
                while(true){
                    map[fruits[prev]]-=1;
                    if(map[fruits[prev]]==0){map.erase(fruits[prev]);prev++;break;}
                    prev++;
                    //i=prev+1;
                }
            }
            else{if(i==n-1){ans=max(ans,n-prev);}}
        }
        return ans;
    }
};