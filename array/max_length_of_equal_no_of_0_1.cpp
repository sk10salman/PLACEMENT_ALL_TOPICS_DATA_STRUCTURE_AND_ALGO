/*
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
       
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                nums[i]=-1;
        }
        map<int,int>m;
      
        m[0]=-1;
        int sum=0,count=0;
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
            if(m.find(sum)!=m.end())
            {
               count=max(i-m[sum],count);
            }
            else
            {
                m[sum]=i;
            }
        }
        return count;
        
    }
};
