int countSumSubsets(int arr[], int N){
    
    // Your code here
    int m=accumulate(arr,arr+N,0);
    int dp[N+1][m+1];
    for(int i=0;i<=N;i++)
       dp[i][0]=1;
    for(int j=1;j<=m;j++)
       dp[0][j]=0;
     for(int i=1;i<=N;i++)
       for(int j=1;j<=m;j++)
       {
           if(arr[i-1]<=j)
             dp[i][j]=dp[i-1][j-arr[i-1]]+dp[i-1][j];
            else
            dp[i][j]=dp[i-1][j];
       }
       int count=0;
     for(int i=2;i<=m;i++)
        if(i%2==0)
          count += dp[N][i];
        return count;
    
}

/*
1
3
1 2 3

Output:
3

Explanation:
Testcase 1: Three subsets are there whose sum of elements is even. Subsets are (3, 2, 1), (1, 3), (2).
