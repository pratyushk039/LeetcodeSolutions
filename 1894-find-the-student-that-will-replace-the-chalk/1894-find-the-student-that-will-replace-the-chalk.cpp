class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long sum=0;
        for(int i:chalk){sum+=i;}
        k = k- sum*(k/sum);
        for(int i =0;i<chalk.size();i++){
            if(chalk[i]>k){return i;}
            k-=chalk[i];
        }
        return 0;
    }
};