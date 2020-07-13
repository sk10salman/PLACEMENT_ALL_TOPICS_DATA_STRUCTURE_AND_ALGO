class Solution {
public:
   bool check(string s)
   {
       int cnt=0;
       for(int i=0;i<s.length();i++)
       {
           if(s[i]=='(')
               cnt++;
          else
          {
              cnt--;
              if(cnt<0)
                  return false;
          }
       }
       return true;
   }
    vector<string> generateParenthesis(int n) {
       string s="";
        vector<string>v;
        for(int i=0;i<n;i++)
            s+="()";
        sort(s.begin(),s.end());
        do
        {
            if(check(s))
                v.push_back(s);
                
        }while(next_permutation(s.begin(),s.end()));
       return v;
    }
};

/*
For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
