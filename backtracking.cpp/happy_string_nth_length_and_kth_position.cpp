class Solution {
public:
   vector<string>v;
    void backtrack(int n,int pos,char prev,string res)
    {
       if(pos==n)
       {
           v.push_back(res);
           cout<<res<<" ";
           return;
       }
       if(prev=='a')
       {
           backtrack(n,pos+1,'b',res+'b');
           backtrack(n,pos+1,'c',res+'c');
       }
        else if(prev=='b')
        {
             backtrack(n,pos+1,'a',res+'a');
           backtrack(n,pos+1,'c',res+'c');
        }
        else
        {
             backtrack(n,pos+1,'a',res+'a');
           backtrack(n,pos+1,'b',res+'b');
        }
        
    }
    string getHappyString(int n, int k) {
    
        
        backtrack(n,1,'a',"a");
        backtrack(n,1,'b',"b");
        backtrack(n,1,'c',"c");
        sort(v.begin(),v.end());
        if(v.size()<k)
            return "";
        return v[k-1];
    }
};


/*
 happy string is a string that:

consists only of letters of the set ['a', 'b', 'c'].
s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is 1-indexed).
For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy strings and strings "aa", "baa" and "ababbc" are not happy strings.

Given two integers n and k, consider a list of all happy strings of length n sorted in lexicographical order.

Return the kth string of this list or return an empty string if there are less than k happy strings of length n.

 

Example 1:

Input: n = 1, k = 3
Output: "c"
Explanation: The list ["a", "b", "c"] contains all happy strings of length 1. The third string is "c".
Example 2:

Input: n = 1, k = 4
Output: ""
Explanation: There are only 3 happy strings of length 1.
Example 3:

Input: n = 3, k = 9
Output: "cab"
Explanation: There are 12 different happy string of length 3 ["aba", "abc", "aca", "acb", "bab", "bac", "bca", "bcb", "cab", "cac", "cba", "cbc"]. You will find the 9th string = "cab"
Example 4:

Input: n = 2, k = 7
Output: ""
Example 5:

Input: n = 10, k = 100
Output: "abacbabacb"
