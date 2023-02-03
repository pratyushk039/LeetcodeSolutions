//WOW !!!!!!!!!!!!! PATIENCE SOLVES THESE PATTERN PROBLEMS!!
class Solution {
public:
    string convert(string s, int numRows) {
        int start=0,n=s.size();
        if(numRows>n){numRows=n;}
        if(numRows==1){return s;}
        string ans="";
        int j;
        for(int i=1;i<=numRows;i++){
            if(i==1){
                j=start;
                while(j<n){ans.push_back(s[j]);j+=2*(numRows-1);}
                start=1;
                continue;
            }
            if(i==numRows){
                j=numRows-1;
                while(j<n){ans.push_back(s[j]);j+=2*(numRows-1);}
                break;
            }
            int row=i;
            j=row-1;
            bool a=true,b=false;
            while(j<n){
            if(a){
                if(j<n)ans.push_back(s[j]);
                j+=2*(numRows-row);
                a=false;b=true;
            }
            if(b){
                if(j<n)ans.push_back(s[j]);
                j+=2*(row-1);
                a=true;b=false;
            }}
        }
        return ans;
    }
};