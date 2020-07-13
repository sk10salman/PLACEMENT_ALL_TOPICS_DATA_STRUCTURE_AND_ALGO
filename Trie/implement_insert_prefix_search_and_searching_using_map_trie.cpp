class Trie {
public:
    /** Initialize your data structure here. */
  struct trie{
    bool isEnd;
 map<char,trie*>child;
    trie() {
            this->isEnd=false;
    }
  };
    trie *root=new trie();
    /** Inserts a word into the trie. */
    void insert(string word) {
        trie *cur=root;
        for(int i=0;i<word.length();i++)
        {
            if(cur->child[word[i]]==NULL)
            {
                trie *temp=new trie();
                cur->child[word[i]]=temp;
                cur=cur->child[word[i]];
            }
            else
                cur=cur->child[word[i]];
                
        }
        cur->isEnd=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
       trie *cur=root;
        for(int i=0;i<word.length();i++)
        {
            if(cur->child[word[i]]==NULL)
                return false;
            cur=cur->child[word[i]];
        }
        return cur->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        trie *cur=root;
        for(int i=0;i<prefix.length();i++)
        {
            if(cur->child[prefix[i]]==NULL)
                return false;
           cur= cur->child[prefix[i]];
            
        }
        return true;
    }
};
/*
Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
