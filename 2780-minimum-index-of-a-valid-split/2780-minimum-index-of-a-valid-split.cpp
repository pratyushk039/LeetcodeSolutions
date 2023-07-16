class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n= nums.size();
        vector<int> pref(n),suf(n);
        int dom,max_freq;
        unordered_map<int,int> map2;
        for(int i=0;i<n;i++){
            map2[nums[i]]+=1;
            int len = i+1;
            if((map2[nums[i]]*2)>len){pref[i]=nums[i];dom=abs(pref[i]);}
            else{
                if(map2[dom]*2>len){pref[i]=dom;}
                else{pref[i]=-1;}
            }
        }
        unordered_map<int,int> map;
        for(int i=n-1;i>-1;i--){
            map[nums[i]]+=1;
            int m = n-i;
            if((map[nums[i]])*2>m){suf[i]=nums[i];dom=abs(suf[i]);}
            else{
                if(map[dom]*2>m){suf[i]=dom;}
                else{suf[i]=-1;}
            }
        }
        for(int i=0;i<n-1;i++){
            //cout<<pref[i]<<" "<<suf[i+1]<<endl;
            if((pref[i]<0) || (suf[i+1]<0)){continue;}
            if(pref[i]==suf[i+1]){return i;}
        }
        return -1;
    }
};