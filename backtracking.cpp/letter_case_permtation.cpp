/*
Examples:
Input: S = "a1b2"
Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

Input: S = "3z4"
Output: ["3z4", "3Z4"]

Input: S = "12345"
Output: ["12345"]*/
class Solution {
public:
    set<string>st;
    void backtrack(string s,int pos,string cur,int n)
    {
        if(pos==n)
        {
            st.insert(cur);
            return;
        }
        if(s[pos]>='a' && s[pos]<='z')
        {
            backtrack(s,pos+1,cur+s[pos],n);
             backtrack(s,pos+1,cur+char(s[pos]-'a'+'A'),n);
        }
        else if(s[pos]>='A' && s[pos]<='Z')
        {
            backtrack(s,pos+1,cur+s[pos],n);
             backtrack(s,pos+1,cur+char(s[pos]-'A'+'a'),n);
        }
        else
        {
            backtrack(s,pos+1,cur+s[pos],n);
        }
    }
    vector<string> letterCasePermutation(string S) {
        backtrack(S,0,"",S.length());
        vector<string>v;
        for(auto x:st)
            v.push_back(x);
        return v;
    }
};
