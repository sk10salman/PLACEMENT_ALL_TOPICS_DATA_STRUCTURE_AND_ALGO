class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m==0 || n==0)
            return 0;
        if(m==n)
            return m;
        long long  x=m;
        for(long long i=m+1;i<=n;i++)
        {x = x&i;
            if(x==0)
                return 0;
        }
        return x;
    }
};
