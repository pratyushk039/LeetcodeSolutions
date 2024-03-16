class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int n = nums.size(),sum=0;
        for(int i=0;i<n;i++){
            string s = to_string(nums[i]);
            int m = s.size();
            char mx='0';
            for(auto c:s){mx=max(mx,c);}
            string k ="";
            for(int j=0;j<m;j++){
                k+=mx;
            }
            int a = stoi(k);
            sum+=a;
        }
        return sum;
    }
};