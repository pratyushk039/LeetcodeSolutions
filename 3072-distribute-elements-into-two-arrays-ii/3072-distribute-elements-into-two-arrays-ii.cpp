class FWT{
    public:
    int n;
    vector<int> fwt;
    FWT(int n){
        this->n=n+1;
        fwt.resize(this->n,1);
    }


    void add(int index , int value){
        ++index; // to offset 1-based indexing
        while(index<n){
            fwt[index]+=value; //operation dependent
            index+=(index&(-index));
        }
        return;
    }

    int sum(int x){
        ++x;  // to offset 1-based indexing
        int ans=0; //operation dependent
        while(x>0){
            ans+=fwt[x]; //operation dependent
            x=(x&(x-1));  // same as x-=(x&(-x)); Both vanish the first set bit from the right.
        }
        return ans;
    }

    int query(int l , int r){
        return (sum(r)-sum(l-1)); //operation dependent
    }
};
class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        if(n==1 || n==2){return nums;}
        map<int,int> val_idx;
        for(auto x:nums){
            val_idx[x]=0;
        }
        int idx=0;
        for(auto it:val_idx){
            val_idx[it.first]=idx;
            idx+=1;
        }
        //we will maintain 2 fenwick trees - frequency arrays to answer greaterCount();
        int m = val_idx.size();
        FWT f1(val_idx.size()),f2(val_idx.size());
        
        vector<int> ans1,ans2,ans;
        ans1.push_back(nums[0]);
        ans2.push_back(nums[1]);
        
        f1.add(val_idx[nums[0]],1); f2.add(val_idx[nums[1]],1);
        int l1=1,l2=1;
        
        for(int i=2;i<n;i++){
            int gc1,gc2;
            gc1 = f1.query(val_idx[nums[i]]+1,m-1);
            gc2 = f2.query(val_idx[nums[i]]+1,m-1);
            
            if(gc1>gc2){f1.add(val_idx[nums[i]],1);l1+=1; ans1.push_back(nums[i]);}
            else if(gc1<gc2){f2.add(val_idx[nums[i]],1);l2+=1;ans2.push_back(nums[i]);}
            else{
                if(l1<=l2){f1.add(val_idx[nums[i]],1);l1+=1;ans1.push_back(nums[i]);}
                else{f2.add(val_idx[nums[i]],1);l2+=1;ans2.push_back(nums[i]);}
            }
            
        }
        
        for(auto x:ans1){ans.push_back(x);}
        for(auto x:ans2){ans.push_back(x);}
        return ans;
        
        
        
        
    }
};