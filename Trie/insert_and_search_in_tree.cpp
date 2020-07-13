#include<iostream>
#include<bits/stdc++.h>
struct trie{
  trie *child[26];
  bool isend;    // check string is end when we search string str it found in mid it is not part of dictionary when its end it true
  
};
using namespace std;

void insert(string str,trie *root)  ///insert string in ROOT dictionary
{
    trie *cur=root;
    for(char x:str)
    {
        int idx=x-'a';
        if(cur->child[idx]==NULL)
        {
            cur->child[idx]=new trie();
            
        }
        cur=cur->child[idx];
    }
    cur->isend=true;
}
bool search(string str,trie *root)    ///search str in ROOT
{
    trie *cur=root;
    for(char x:str)
    {
        int idx=x-'a';
        if(cur->child[idx]==NULL)
           return false;
         cur=cur->child[idx];
    }
    return cur->isend;
}

int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	   trie *root=new trie;
	    int n;
	    cin>>n;
	    while(n--)
	    {
	        string str;
	        cin>>str;
	        insert(str,root);
	    }
	    string str;
	        cin>>str;
	
	   cout<<search(str,root)<<endl;
	}
	return 0;
}
