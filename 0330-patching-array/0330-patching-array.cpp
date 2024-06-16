class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long range = 0,ans=0,m = nums.size();
        
        for(int i=0;i<m;i++){
            if(n<=range){return ans;}
            if(nums[i]<=range+1){range+=nums[i];} //nums[i] continues and extends our covered range
            else{
                //range break - patch nums [i].
                while(nums[i]>range+1){
                    ans+=1;
                    range = 2*range+1; // add the next consecutive element
                    if(n<=range){return ans;} // edge case - what if n is satisfied right here
                }
                range+=nums[i]; //first condition still applies, beacuse nums[i] extends our range further.
            }
            
        }
        while(range<n){
            //existing elements could'nt satisfy n.
            ans+=1;
            range = 2*range+1;
            
        }
        return ans;
        
    }
};