class Solution {
public:
   
    
    bool isMatch(string s, string p) {
       int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] || (i > 0 && dp[i - 1][j]);
                } else {
                    dp[i][j] =
                        i > 0 && (dp[i - 1][j - 1] &&
                                  (s[i - 1] == p[j - 1] || p[j- 1] == '?'));
                }
            }
        }
        return dp[m][n];
       
    }
};

/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like ? or *.
Example 1:

Input:
s = "aa"
p = "a"
