class Solution {
public:
    int m=0;
    int dp[20][20];
    int solve(vector<int>& nums,int s,int e)
    { 
       
        if(s>e)
            return 0;
         if(s==e)
            nums[s];
        if(dp[s][e]!=-1)
            return dp[s][e];
        int r= nums[s]+solve(nums,s+1,e-1);
                          int x=nums[s]+ solve(nums,s+2,e);
             int t= nums[e]+solve(nums,s+1,e-1);
                          int y=nums[e]+ solve(nums,s,e-2);
       
        return dp[s][e]=max(min(r,x),min(t,y));
        
    }
    bool PredictTheWinner(vector<int>& nums) {
        if(nums.size()<=2)
            return true;
        memset(dp,-1,sizeof(dp));
       int p=solve(nums,0,nums.size()-1);
        cout<<p<<" ";
        return  p>=(accumulate(nums.begin(),nums.end(),0)/2.0)?true:false;
    }
};

/*
Given an array of scores that are non-negative integers. Player 1 picks one of the numbers from either end of the array followed by the player 2 and then player 1 and so on. Each time a player picks a number, that number will not be available for the next player. This continues until all the scores have been chosen. The player with the maximum score wins.

Given an array of scores, predict whether player 1 is the winner. You can assume each player plays to maximize his score.

Example 1:
Input: [1, 5, 2]
Output: False
Explanation: Initially, player 1 can choose between 1 and 2. 
If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5, then player 1 will be left with 1 (or 2). 
So, final score of player 1 is 1 + 2 = 3, and player 2 is 5. 
Hence, player 1 will never be the winner and you need to return False.
Example 2:
Input: [1, 5, 233, 7]
Output: True
Explanation: Player 1 first chooses 1. Then player 2 have to choose between 5 and 7. No matter which number player 2 choose, player 1 can choose 233.
Finally, player 1 has more score (234) than player 2 (12), so you need to return True representing player1 can win
