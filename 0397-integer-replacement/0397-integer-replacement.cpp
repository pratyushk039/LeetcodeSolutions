unordered_map<long long int,int> umap;
class Solution {
public:
    int util(long long n){
        if(n==1){
            return 0;
        }
        int a=INT_MAX,b=INT_MAX,c=INT_MAX;
        if(n%2==0){
            if(umap.find(n/2)==umap.end()){
                umap[n/2]=util(n/2);
            }
            a=1+umap[n/2];
        }
        else{
            if(umap.find(n+1)==umap.end()){
                umap[n+1] = util(n+1);
            }
            if(umap.find(n-1)==umap.end()){
                umap[n-1] = util(n-1);
            }
            b = 1+umap[n+1];
            c = 1+umap[n-1];
            b=min(b,c);
        }
        return min(a,b);
    }
    int integerReplacement(int n) {
        if(umap.find(n)==umap.end()){
        return umap[n] = util(1ll*n);
        }
        else return umap[n];
    }
};