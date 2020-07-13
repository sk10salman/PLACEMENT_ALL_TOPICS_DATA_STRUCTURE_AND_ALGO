class Solution {
public:
    int dp[500][500];
    int solve(vector<int>&nums,int start,int end)
    {
        if(start>end)
            return 0;
        if(dp[start][end]!=-1)
            return dp[start][end];
        int a=nums[start]+min(solve(nums,start+1,end-1),solve(nums,start+2,end));
        int b=nums[end]+min(solve(nums,start+1,end-1),solve(nums,start,end-2));
        return dp[start][end]=max(a,b);
    }
    bool stoneGame(vector<int>& piles) {
          memset(dp,-1,sizeof(dp));
        int mn=solve(piles,0,piles.size()-1);
        int sum=0;
      
        for(auto x:piles)
             sum +=x;
        if(mn>sum/2)
            return true;
        return false;
    }
};
