class Solution {
public:
    int findComplement(int num) {
           
            int ans=0;
            long long c=1;
            
            while(num)
            {
               ans = ans+((1&num)^1)*c;
                c *= 2;
                num =num>>1;
            }
        return ans;
    }
};

/*
Given a positive integer num, output its complement number. The complement strategy is to flip the bits of its binary representation.

 

Example 1:

Input: num = 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
Example 2:

Input: num = 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
