class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if(s.length()==0)
            return true;
    int k=1;
      for(int i=0;i<s.length();i++)
      {
          string a=s.substr(0,k);
         // cout<<a<<" ";
          for(int j=k;j<s.length();j=j+k)
          {
             // cout<<s.substr(j,k)<<" ";
              if(s.substr(j,k)!=a)
                  j=s.length()+10;
              if(j+k==s.length())
                  return true;
          }
          k++;
      }
        return false;
    }
};

/*
Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.

 

Example 1:

Input: "abab"
Output: True
Explanation: It's the substring "ab" twice.
Example 2:

Input: "aba"
Output: False
Example 3:

Input: "abcabcabcabc"
Output: True
Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)


