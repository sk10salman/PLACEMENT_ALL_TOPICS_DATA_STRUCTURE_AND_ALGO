class Solution {
public:
    #define ll long long
    ll mod =1000000007;
    unordered_map<string,ll>mp;
    ll go(int n,int f,int sum)
    {
        if(sum==0&&n==0)
            return 1;
        if(n==0||sum<0)
            return 0;
        string str=to_string(n)+"|"+to_string(sum);
       
        if(mp.count(str))
            return mp[str];
         long long res=0;
        for(int i=1;i<=f;i++)
        {   if(i<=sum)
            res =res+go(n-1,f,sum-i)%mod;
        }
        return mp[str] = res;
    }
    int numRollsToTarget(int d, int f, int target) {   //main function
      
        return go(d,f,target)%mod;
    }
};

/*
You have d dice, and each die has f faces numbered 1, 2, ..., f.

Return the number of possible ways (out of fd total ways) modulo 10^9 + 7 to roll the dice so the sum of the face up numbers equals target.

 

Example 1:

Input: d = 1, f = 6, target = 3
Output: 1
Explanation: 
You throw one die with 6 faces.  There is only one way to get a sum of 3.
