class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if(n==k){return "0";}
        stack<int> s;
        
        for(int i=0;i<n;i++){
            auto ch = num[i];
            while((k>0) && (!s.empty()) && (num[s.top()]>ch)){s.pop();k-=1;}
            s.push(i);
        }
        int lead=INT_MAX;
        if(s.size()==n){
        //remove leading zeroes.
        for(int i=0;i<num.size();i++){
            if(num[i]!='0'){lead=i;break;}
        }
            return lead==INT_MAX?"0":num.substr(lead,n-k);
        }
        while(k>0){
            s.pop();
            k-=1;
        }
        string ans = "";
        while(!s.empty()){ans = num[s.top()]+ans;s.pop();}
        lead=INT_MAX;
        //remove leading zeroes.
        for(int i=0;i<ans.size();i++){
            if(ans[i]!='0'){lead=i;break;}
        }
        //substring from lead till end.
        if(lead==INT_MAX){return "0";}
        else{ans = ans.substr(lead);return ans;}
    }
};