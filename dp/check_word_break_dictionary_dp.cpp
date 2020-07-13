class Solution {
public:
    
    bool wordBreak(string s, vector<string>& wordDict) {
        const auto N = s.size();
        const auto M = wordDict.size();
        if (N == 0 || M == 0) return false;

        std::vector<bool> dp(N + 1, false);dp[0] = true;
        for (int i = 0; i < N; ++i) {
            for(auto& str : wordDict) {
                int len = str.size();
                if(dp[i]) {
                    if(s.substr(i,len) == str) {
                        dp[i + len] = true;
                    }
                }
            }
        }
        return dp[N];
    }
    
};
