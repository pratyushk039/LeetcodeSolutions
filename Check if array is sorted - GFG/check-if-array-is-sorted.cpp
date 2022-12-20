//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    bool arraySortedOrNot(int arr[], int n) {
        // for(int i=1;i<n;i++){
        //     int k=i;
        //     int v[n];
        //     for(int i=0;i<n;i++){v[i]=arr[i];}
        //     for(int j=i-1;j>-1;j--){
        //         if(v[k]<v[j]){
        //             swap(v[k],v[j]);
        //             k-=1;
        //         }
        //         else{break;}
        //     }
        for(int i=1;i<n;i++){if(arr[i-1]>arr[i]){return false;}}
        return true;
    }
        // code here
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        bool ans = ob.arraySortedOrNot(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends