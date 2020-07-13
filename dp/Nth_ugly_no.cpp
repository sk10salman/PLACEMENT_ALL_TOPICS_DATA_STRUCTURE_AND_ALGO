class Solution {
public:
   
    int nthUglyNumber(int n) {
     
       int ugly[n];
        ugly[0]=1;
        int i2=0,i3=0,i5=0,next2=2,next3=3,next5=5,next_ugly=1;
            
        for(int i=1;i<n;i++)
        {
            next_ugly=min(next2,min(next3,next5));
            ugly[i]=next_ugly;
            if(next_ugly==next2)
            {
                i2++;
                next2=ugly[i2]*2;
            }
             if(next_ugly==next3)
            {
                i3++;
                next3=ugly[i3]*3;
            }
           if(next_ugly==next5)
            {
                i5++;
                next5=ugly[i5]*5;
            }
        }
        return ugly[n-1];
    }
};
