class Solution {
public:
   // bool check(string s)
   // {
   //     int cnt=0;
   //     for(int i=0;i<s.length();i++)
   //     {
   //         if(s[i]=='(')
   //             cnt++;
   //        else
   //        {
   //            cnt--;
   //            if(cnt<0)
   //                return false;
   //        }
   //     }
   //     return true;
   // }
    
    void go_back(int n,string s,vector<string>&v,int open,int close)
    {
        if(close==n)
        {
            v.push_back(s);
            return;
        }
        if(open>close)
        {
           
            go_back(n,s+')',v,open,close+1);
        }
        if(open<n)
        {
           
            go_back(n,s+'(',v,open+1,close);
        }
    }
    vector<string> generateParenthesis(int n) {
       string s="";
        vector<string>v;
//         for(int i=0;i<n;i++)
//             s+="()";
//         sort(s.begin(),s.end());
//         do
//         {
//             if(check(s))
//                 v.push_back(s);
                
//         }while(next_permutation(s.begin(),s.end()));
        go_back(n,"",v,0,0);
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
