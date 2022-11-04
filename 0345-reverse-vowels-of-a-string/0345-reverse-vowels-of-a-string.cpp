class Solution {
public:
    string reverseVowels(string s) {
        int n = s.size(),i=0,j=n-1;
        unordered_set<char> st;
        st.insert('A');st.insert('E');st.insert('I');st.insert('O');st.insert('U');
        st.insert('a');st.insert('e');st.insert('i');st.insert('o');st.insert('u');
        while(i<j){
            if(st.find(s[i])!=st.end() && st.find(s[j])!=st.end()){
                swap(s[i],s[j]);
                i+=1;j-=1;
            }
            if(st.find(s[i])==st.end()){i+=1;}
            if(st.find(s[j])==st.end()){j-=1;}
        }
        return s;
    }
};