class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<int> vec(n-1); // diff array
        if(n<3){return 0;}
        for(int i=1;i<n;i++){
            vec[i-1]=nums[i]-nums[i-1];
        }
        int ans=0,i=0,j=1;
            int temp=1;
            while(j<n){
                if(vec[i]==vec[j]){temp+=1;j+=1;}
                else{
                    temp+=1;
                    ans+=(temp-1)*(temp-2)/2;
                    i=j;
                    j+=1;
                    temp=1;
                }
                if(j==n-1){
                    temp+=1;
                    ans+=(temp-1)*(temp-2)/2;
                    break;
                }
            }
        return ans;
    }
};