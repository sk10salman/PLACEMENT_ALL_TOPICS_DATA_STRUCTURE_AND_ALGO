/*
Print the duplicate elements from the given array. The order of the output should be in sorted order. Print -1 if no duplicate exists.
*/#include <bits/stdc++.h>
using namespace std;
vector<int> duplicates(int arr[], int n);
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<int> ans = duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


vector<int> duplicates(int a[], int n) {
    // code here
    vector<int>v;
   /* map<int,int>m;
    for(int i=0;i<n;i++)
      m[a[i]]++;
    for(auto i=m.begin();i!=m.end();i++)
       if(i->second>=2)
            v.push_back(i->first);*/
    sort(a,a+n);
    v.push_back(-1);
    for(int i=1;i<n;i++)
       {
           if(a[i]==a[i-1]&& a[i]!=v.back())
             v.push_back(a[i]);
       }
      v.erase(v.begin());
    if(v.size()==0)
      v.push_back(-1);
     return v;
}

