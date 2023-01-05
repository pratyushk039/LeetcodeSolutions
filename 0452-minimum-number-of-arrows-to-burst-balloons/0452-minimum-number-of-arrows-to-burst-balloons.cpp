class Solution {
public:
    //maintain a greedy streak.
    static bool comp(vector<int>&a,vector<int>&b){
        return a[0]<b[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size(),i=1,ans=0;
        sort(points.begin(),points.end(),comp);
        int pivot = points[0][1];
        while(i<n){
            if(pivot<points[i][0]){
                pivot=points[i][1];
                i+=1;
                ans+=1;
                continue;
            }
            pivot = min(points[i][1],pivot);
            i+=1;
        }
        ans+=1;
        return ans;
    }
};