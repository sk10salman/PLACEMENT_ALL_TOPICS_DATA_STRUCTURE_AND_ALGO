/*
For each test case in a new line output will be the length of the longest consecutive increasing sub-sequence present in the array A[ ].

Constraints:
1 <= T <= 100
1 <= N <= 106
1 <= Ai <= 108

Example(To be used only for expected output):
Input:
2
7
1 9 3 10 4 20 2
11
36 41 56 35 44 33 34 92 43 32 42
Output:
4
5
*/

#include <bits/stdc++.h>

using namespace std;

int findLongestConseqSubseq(int [], int );

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		
		int a[n];
		
		// input array elements
		for(int i=0;i<n;i++)
		    cin>>a[i];
		
		cout<< findLongestConseqSubseq(a, n)<<endl;
		
	}
	return 0;
}// } Driver Code Ends




// function to find longest consecutive subsequence
// n : size of array
// arr[] : input array
int findLongestConseqSubseq(int arr[], int n)
{
    //Your code here
   
    int count=0;
    int num=0,c=0;
    map<int,int>m;
    for(int i=0;i<n;i++)
      m[arr[i]]=1;
   for(auto i=m.begin();i!=m.end();i++)
    {
        if(i->first==num+1)
        {
            count++;
            num=i->first;
        }
        else
        {
            count=1;
            num=i->first;
        }
        c=max(count,c);
    }
    return c;
}
