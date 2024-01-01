class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int xyp=0,yxp=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]=='x' && s2[i]=='y'){xyp+=1;}
            if(s1[i]=='y' && s2[i]=='x'){yxp+=1;}
        }
        if((xyp+yxp)%2!=0){return -1;}
        if(xyp%2==0){return xyp/2+yxp/2;}
        else{
            return (xyp-1)/2 + (yxp-1)/2 +2;
        }
    }
};