class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int temp=num2;
        int setbits=0;
        while(temp>0){
            temp=temp&(temp-1);
            setbits+=1;
        }
        int ans=0,mask;
        temp=0;
        
        for(int i=30;i>=0;i--){
            mask=(1<<i);
            if(setbits>0){
                if((mask&num1)!=0){
                    ans+=mask;
                    temp=temp^mask;
                    setbits-=1;
                    if(temp==0){break;}
                }
            }
            else{break;}
        }
        
        if(setbits>0){
            for(int i=0;i<31;i++){
                int mask2=(1<<i);
                if((ans&mask2)==0){
                    ans=ans|mask2;
                    setbits-=1;
                    if(setbits==0){break;}
                }
            }
        }  
        return ans;
    }
};