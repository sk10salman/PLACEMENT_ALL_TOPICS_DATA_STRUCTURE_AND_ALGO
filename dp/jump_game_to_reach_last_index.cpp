class Solution {
public:
    bool canJump(vector<int>& nums) {
       /* method 1:
       int n=nums.size(), i, j=n-1;
        
        //Go from right
        for(i = n-1 ; i >= 0; i--)
        {
            if(i+nums[i]>=j)
                j=i;
        }
        
        return j==0;*/
        int n=nums.size(),reach=0;
        if(n<=1)
             return true;
       for(int i=0;i<n;i++)
       {
           if(reach<i)
               return false;
           reach = max(reach,nums[i]+i);
       }
        return true;
        
    }
};


/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

