#include <bits/stdc++.h>
using namespace std;

int maxLen(int arr[], int n);

int main() {
    // your code goes here
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << maxLen(a, n) << endl;
    }
    return 0;
}// } Driver Code Ends


/*You are required to complete this method*/

// arr[] : the input array containing 0s and 1s
// N : size of the input array

// return the maximum length of the subarray
// with equal 0s and 1s
int maxLen(int A[], int n) {
    // Your code here
    
    unordered_map<int,int> m;
    int sum = 0, ans = INT_MIN;
    
    for(int i = 0;i<n;i++)
        if(A[i] == 0)
            A[i] = -1;
            
    for(int i = 0;i<n;i++)
    {
        sum += A[i];
        if(sum == 0)
            ans = max(ans,i+1);
            
        if(m.find(sum) != m.end())
        {
            ans = max(ans,i-m[sum]);
        }
        else
            m[sum] = i;
    }
    
    if(ans == INT_MIN)
        return 0;
    return ans;
}

