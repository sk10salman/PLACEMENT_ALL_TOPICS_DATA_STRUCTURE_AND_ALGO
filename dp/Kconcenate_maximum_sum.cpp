class Solution {
public:
    int kConcatenationMaxSum(vector<int>& nums, int k) {
       if(nums.size()==0||k==0)
            return 0;
        long long sum=0;
        sum=accumulate(nums.begin(),nums.end(),0);
        sum %=1000000007;
        long long x=0;
        if(k>2)
        {
            if(sum>0)
                x=((k-2)*sum)%1000000007;
            k = 2;
        }
      vector<int>num;
        for(int i=0;i<k;i++)
        {
             for(auto x:nums)
                 num.push_back(x);
        }
        long long s=0,s1=0;
        for(auto x:num)
        {
            s+=x;
            s1=max(s,s1);
            if(s<0)
                s=0;
        }
        sum = (s1+x)%1000000007;
        return (sum)%1000000007;
    }
};

/*
Given an integer array arr and an integer k, modify the array by repeating it k times.

For example, if arr = [1, 2] and k = 3 then the modified array will be [1, 2, 1, 2, 1, 2].

Return the maximum sub-array sum in the modified array. Note that the length of the sub-array can be 0 and its sum in that case is 0.

As the answer can be very large, return the answer modulo 10^9 + 7.

 

Example 1:

Input: arr = [1,2], k = 3
Output: 9
Example 2:

Input: arr = [1,-2,1], k = 5
Output: 2
Example 3:

Input: arr = [-1,-2], k = 7
Output: 0
