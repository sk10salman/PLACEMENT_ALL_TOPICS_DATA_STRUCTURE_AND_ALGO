class Solution {
public:
    #include<bits/stdc++.h>
    vector<int> minSubsequence(vector<int>& nums) {
        if(nums.size()<=1)
            return nums;
        int sum = accumulate(nums.begin(),nums.end(),0);
        sort(nums.begin(),nums.end());
        vector<int>v;
        int x=0;
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(x>sum-x)
                break;
            else
            {
                x+=nums[i];
                v.push_back(nums[i]);
            }
        }
        return v;
    }
};


/*
Input: nums = [4,4,7,6,7]
Output: [7,7,6] 
Explanation: The subsequence [7,7] has the sum of its elements equal to 14 which is not strictly greater than the sum of elements not included (14 = 4 + 4 + 6). Therefore, the subsequence [7,6,7] is the minimal satisfying the conditions. Note the subsequence has to returned in non-decreasing order.  

*/
