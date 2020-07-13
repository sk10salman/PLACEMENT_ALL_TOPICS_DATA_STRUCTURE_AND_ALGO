/*
Input: dict = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"
*/

class Solution {
public:
    struct trie
    {
        bool isEnd;
        map<char,trie*>child;
        trie()
        {
            this->isEnd=false;
        }
    };
    trie *root=new trie();
     void insert(string word)
     {
         trie *cur=root;
         for(int i=0;i<word.length();i++)
         {
             if(cur->child[word[i]]==NULL)
             {
                 trie *temp=new trie();
               cur->child[word[i]]=temp;
                 cur=temp;
             }
             else
                 cur= cur->child[word[i]];
         }
         cur->isEnd=true;
     }
    string search(string w)
    {
          trie *cur=root;
           for(int i=0;i<w.length();i++)
           {
               if(cur->isEnd)
                   return w.substr(0,i);
               if(cur->child[w[i]]==NULL)
                   return w;
               cur=cur->child[w[i]];
           }
        return w;
    }
    string replaceWords(vector<string>& dict, string sentence) {
        for(auto x:dict)
            insert(x);
        istringstream ss(sentence);
        string a="",word;
        while(getline(ss,word,' '))
        {
            a += search(word)+" ";
        }
        a.pop_back();
        return a;
    }
};



