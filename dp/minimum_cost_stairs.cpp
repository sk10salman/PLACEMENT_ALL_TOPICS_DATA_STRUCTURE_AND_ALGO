/*
On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).

Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1.

Example 1:
Input: cost = [10, 15, 20]
Output: 15
Explanation: Cheapest is start on cost[1], pay that cost and go to the top.
Example 2:
Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
Output: 6
Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[3].
*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
         int n=cost.size();
      
        if(n<=0)
            return n;
        if(n==1)
            return cost[0];
        if(n==2)
            return min(cost[0],cost[1]);
        int dp[n];
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<n;i++)
            dp[i]=min(dp[i-2],dp[i-1])+cost[i];
        return min(dp[n-1],dp[n-2]);
    }
    
};
