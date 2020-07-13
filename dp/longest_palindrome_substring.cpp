#include <bits/stdc++.h>
using namespace std;
string longestPalindrome(string);
/* eg:: aaaabbaa
    its table would look like 
    \  a a a a b b a a
    a| 1 1 1 1 0 0 0 0
    a| 0 1 1 1 0 0 0 0
    a| 0 0 1 1 0 0 0 1
    a| 0 0 0 1 0 0 1 0 
    b| 0 0 0 0 1 1 0 0
    b| 0 0 0 0 0 1 0 0
    a| 0 0 0 0 0 0 1 1
    a| 0 0 0 0 0 0 0 1
    
    Here 1 represents there exists a palindrome from i to j
    1. All diagonals are 1 as all single elements are palindrome
    2. For 2 elements to be palindrome both the character should be equal
    3. For 3 elements and so on we have to check 2 condition if it is a palindrome:
        a). First and last character should be same.
        b). String in between should be palindrome (Given by dp[i+1][j-1])
*/

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << longestPalindrome(str) << endl;
    }
    return 0;
}// } Driver Code Ends

string longestPalindrome(string s) {
    int n=s.length();
    int dp[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            dp[i][j]=0;// Initialize dp table with all zeroes
        }
    }
    for(int i=0;i<n;i++)
    dp[i][i]=1;   // We know single element is always a palindrome so we put 1 in diagonals
    
    //This is to check whether 2 elements form a palindrome
    for(int i=0;i<n;i++)
       if(s[i+1]==s[i])
        dp[i][i+1]=1;
    // This is mainly checking if first and last characters are same and in between string is palindrome
    // then put yes in that dp state
    for(int k=3;k<=n;k++)
    {
        for(int i=0;i<n-k+1;i++)
        {
            int j=i+k-1;
            if(s[j]==s[i]&&dp[i+1][j-1]==1)
            dp[i][j]=1;
        }
    }
    
    // For finding largest string we travel every row and find the row with 1 at greatest distance
    int maxm=0,x=0,y=0;
    for(int i=0;i<n;i++)
    {
        int diff=0;
        for(int j=i;j<n;j++)
        {
            if(dp[i][j]==1)
            {
                diff=j-i;
            }
            if(diff>maxm)
            {maxm=diff;
            x=i;y=j;}
        }
    }
    string res="";
    for(int i=x;i<=y;i++)
    {
        res+=s[i];
    }
    return(res);
}
