class Solution {
public:
    bool ugly(int n)
    {
        while(n&&n%2==0)
            n /=2;
         while(n&&n%3==0)
            n /=3;
         while(n&&n%5==0)
            n /=5;
        if(n==1)
            return true;
        return false;
        
    }
    int nthUglyNumber(int n) {
     
        int count=1;
        int i=1;
        while(count<n)
        {
            i++;
            if(ugly(i))
                count++;
            
        }
        return i;
    }
};
