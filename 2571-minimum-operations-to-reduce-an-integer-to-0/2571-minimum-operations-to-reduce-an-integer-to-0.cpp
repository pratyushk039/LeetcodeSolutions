class Solution {
public:
    int numBits(int x){
        if(x==0){return 0;}
        int ans=0;
        while(x>0){
            if(((x)&(1))!=0){
                ans+=1;
            }
            x= (x>>1);
        }
        return ans;
    }
    int minOperations(int n) {
        int consBits=0 , ans=0;
        for(int i=0;i<31;i++){
            int bm = (1<<i);
            //cout<<bm<<endl;
            int currbit = ((n)&(bm))==0?0:1;
            if(currbit==1){consBits+=1;}
            else{
                if(consBits==0){continue;}
                if(consBits==1){consBits=0;continue;}
                if(consBits>1){int newB= (bm>>consBits); n+=newB;ans+=1;i-=1;}
                consBits=0;
            }
            //cout<<n<<endl;
        }
        return ans+numBits(n);
    }
};