void backtrack(string s,int pos,string temp)
{
    if(pos==s.length())
    {
        cout<<temp<<"$";
        return;
    }
    backtrack(s,pos+1,temp+s[pos]);
    backtrack(s,pos+1,temp+" "+s[pos]);
     
}

void  printSpace(char str[])  //given function
{
//Your code here
   std::string s1;
   int n=strlen(str);
   for(int i=0;i<n;i++)
    { 
      char c=str[i];
      //cout<<c<<" ";
     s1.push_back(c);
    }
 //  cout<<s1<<" ";
string temp="";
temp+=s1[0];
   backtrack(s1,1,temp);
}

/*
Input
2
abc
xy
Output
abc$ab c$a bc$a b c$
xy$x y$
*/
