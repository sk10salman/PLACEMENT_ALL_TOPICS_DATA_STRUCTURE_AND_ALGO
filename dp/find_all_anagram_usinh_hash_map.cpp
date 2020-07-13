class Solution {
public:   
    vector<int> findAnagrams(string s, string p) {
        
      vector<int>res;
        if(s.length() == 0)return res;
        unordered_map<char,int>mp,mp1;
        for(int i=0;i<p.length();i++){
            mp[p[i]]++;
            mp1[s[i]]++;
        }
        int j=0;
        if(mp == mp1){
            res.push_back(0);
        }
        for(int i=p.length();i<s.length();i++){
             ++mp1[s[i]];
             --mp1[s[j]];
             if(mp1[s[j]] == 0) mp1.erase(s[j]);
             if(mp == mp1){
                 res.push_back(j+1);
              }
            ++j;    
        }
        return res;
    }
};


/*
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
