
vector<bool> seive(int n)
{
    vector<bool>dp(n+1,true);
    dp[0]=false;
    dp[1]=false;
    for(int i=2;i*i<=n;i++)
    {
        if(dp[i]==true)
        {
            for(int p=i*i;p<=n;p=p+i)
               dp[p]=false;
        }
    }
    return dp;
}
vector<int> Solution::primesum(int A) {
    vector<bool>dp=seive(A);
    vector<pair<int,int>>v1;
    for(int i=2;i<=A/2+1;i++)
    {
        if(dp[i]==1&&dp[A-i]==1)
         {
             v1.push_back({i,A-i});
         }
    }
    sort(v1.begin(),v1.end());
    vector<int>v;
    v.push_back(v1[0].first);
     v.push_back(v1[0].second);
    return v;
}

/*

Input : 4
Output: 2 + 2 = 4
