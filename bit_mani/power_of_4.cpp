class Solution {
public:
    bool isPowerOfFour(int num) {
          if(num==0)
              return 0;
        if(num==1)
            return 1;
           return (log10(num)/log10(4))==ceil(log10(num)/log10(4));
    }
};

/*
Input: 16
Output: true
Example 2:

Input: 5
Output: false

class Solution {
public:
    bool isPowerOfFour(int num) {
       if(num == 0){
           return false;
       }
        else{
            while(num > 1 || num < 0){
                if(num % 4 != 0){
                    return false;
                }
                else{
                    num /= 4;
                }
            }
        }
        return true;
    }
};
