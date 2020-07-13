/*You are required to complete this method */
long long getSmallestDivNum(long long n)
{
    //Your code here
    if(n<=2)
    return n;
    long long x=2;
    long long gcd1=1;
    for(long long i=3;i<=n;i++)
    {
        
        gcd1 = __gcd(i,x);
        x=x*i;
        x /=gcd1;
    }
    return x;
}

