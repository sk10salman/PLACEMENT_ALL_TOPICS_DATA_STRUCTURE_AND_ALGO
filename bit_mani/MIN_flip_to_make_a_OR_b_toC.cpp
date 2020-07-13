class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans=0;
        for(int i=0;i<=31;i++)
        {
            bool x=false,y=false,z=false;
          
            if(a&1<<i)
                x=true;
            if(b&1<<i)
                y=true;
            if(c&1<<i)
                z=true;
            if(z==false)
            {
                if(x==true&&y==true)
                    ans +=2;
                else if(x==true||y==true)
                    ans +=1;
                
            }
            else if(z==true) {
                if(x==false&&y==false)
                     ans +=1;
            }
        }
        return ans;
    }
};
/*
Input: a = 2, b = 6, c = 5
Output: 3
Explanation: After flips a = 1 , b = 4 , c = 5 such that (a OR b == c)
Example 2:

Input: a = 4, b = 2, c = 7
Output: 1
Example 3:

Input: a = 1, b = 2, c = 3
Output: 0
