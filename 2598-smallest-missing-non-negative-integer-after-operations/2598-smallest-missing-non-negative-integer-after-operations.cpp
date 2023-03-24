class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int> map;
        for(int i:nums){
            int k = i%value<0?value+i%value:i%value;
            map[k]+=1;
        }
        for(int i=0;i<=1e5+1;i++){
            if(map.find(i%value)==map.end()){return i;}
            else{
                map[i%value]-=1;
                if(map[i%value]==0){map.erase(i%value);}
            }
        }
        return 0;
    }
};