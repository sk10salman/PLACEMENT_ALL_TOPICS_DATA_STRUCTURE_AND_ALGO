class Solution {
public:
    string solve(string s)
    {
        string a="";
        int count=1;
        char ch=s[0];
        for(int i=1;i<s.length();i++)
        {
            if(ch==s[i])
                count++;
            else
            {
                a += (count+'0');
                a += (ch);
                ch=s[i];
                count=1;
            }
        }
         a += (count+'0');
         a += (ch);
        return a;
    }
    string countAndSay(int n) {
        
        vector<string>s;
        s.push_back("1");
        s.push_back("11");
        for(int i=2;i<n;i++)
        {
            string a=solve(s.back());
           
            s.push_back(a);
        }
        return s[n-1];
    }
};
/*
The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11          -ek baar 1 aaya
3.     21           -2 baar 1 aaya             previous se count kar rahe hai 
4.     1211          -1 baar 2 and 1 baar 1 
5.     111221       - 1 baar 1 1 baar 2 2 baar 1
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
