class Solution {
public:
    bool winnerOfGame(string cls) {
        int a=0,b=0,cnta=0,cntb=0,n=cls.size();
        if(cls[n-1]=='B'){cls.push_back('A');}
        if(cls[n-1]=='A'){cls.push_back('B');}
        for(int i=0;i<=n;i++){
            if(cls[i]=='B'){
                cntb+=1;
                a+=max(0,cnta-2);
                cnta=0;
            }
            else{
                cnta+=1;
                b+=max(cntb-2,0);
                cntb=0;
            }
        }
        //cout<<a<<" "<<b<<endl;
        if(a>b)return true;
        return false;
    }
};