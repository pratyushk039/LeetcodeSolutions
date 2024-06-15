#define INT_MIN 0
class SGT {
    public:
    int n;
    vector<pair<int, int>> st; // Each node stores {max_value, index}

    SGT(int n) {                                 
        this->n = n;
        st.resize(4 * n, {0, -1});
    }

    void build(int start, int end, int node, vector<int> &v) {
        if (start == end) {
            st[node] = {v[start], start};
            return;
        }
        
        int mid = (start + end) / 2;

        build(start, mid, 2 * node + 1, v);
        build(mid + 1, end, 2 * node + 2, v);

        st[node] = max(st[2 * node + 1], st[2 * node + 2]);
        return;
    }

    pair<int, int> query(int start, int end, int node, int l, int r) {
        if (start > r || end < l) {
            return {INT_MIN, -1}; // Use INT_MIN to ensure correct max comparison
        }

        if (l <= start && r >= end) {
            return st[node];
        }

        int mid = (start + end) / 2;

        pair<int, int> q1 = query(start, mid, 2 * node + 1, l, r);
        pair<int, int> q2 = query(mid + 1, end, 2 * node + 2, l, r);

        return max(q1, q2);
    }

    void update(int start, int end, int index, int node, int value) {
        if (start == end) {
            st[node] = {value, index};
            return;
        }

        int mid = (start + end) / 2;
            
        if (index <= mid) {
            update(start, mid, index, 2 * node + 1, value);
        } else {
            update(mid + 1, end, index, 2 * node + 2, value);
        }

        st[node] = max(st[2 * node + 1], st[2 * node + 2]);
        return;
    }

    void build(vector<int> &v) {
        build(0, n - 1, 0, v);
        return;
    }

    pair<int, int> query(int l, int r) {
        return query(0, n - 1, 0, l, r);
    }

    void update(int index, int value) {
        update(0, n - 1, index, 0, value);
        return;
    }
};

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& ps, vector<int>& cl) {
        vector<vector<int>> arr;
        int n  = ps.size();
        if(k>n){k=n;}
        for(int i = 0;i<n;i++){
            arr.push_back({cl[i],ps[i]});
            
        }
        sort(arr.begin(),arr.end());
        vector<int> cls,pss;
        for(int i=0;i<n;i++){
            cls.push_back(arr[i][0]);
            pss.push_back(arr[i][1]);
        }
        
        int cnt = 0;
        //segment tree
        SGT sgt(n);
        sgt.build(pss);
        // cout<<sgt.query(0,2)<<" "<<sgt.query(0,1)<<" "<<sgt.query(0,0)<<endl;
        
        
        while(cnt<k){
            cnt++;
            int idx = upper_bound(cls.begin(),cls.end(),w) - cls.begin()-1;
            
            auto p = sgt.query(0,idx);
            
            w+=p.first;
            sgt.update(p.second,0);
        }
        return max(0,w);
    }
};