/*
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

Example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
*/

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        
    }
    
    /** Adds a word into the data structure. */
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
    void addWord(string word) {
        trie *cur=root;
        for(int i=0;i<word.length();i++)
        {
            if(cur->child[word[i]]==NULL)
            {
                trie *temp=new trie;
                cur->child[word[i]]=temp;
                cur=temp;
                
            }
            else
                cur=cur->child[word[i]];
        }
        cur->isEnd=true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool tsearch(string word,trie *root1) {
        trie *cur=root1;
        //  bool accept=false;
        for(int i=0;i<word.length();i++)
        {
            if(word[i]!='.')
            {
                if(cur->child[word[i]]==NULL)
                    return false;
                cur=cur->child[word[i]];
            }
            else if(word[i]=='.')
            {
               
            
                
                    for(auto x:cur->child)
                    {
                       
                       if(x.second!=NULL&&tsearch(word.substr(i+1,word.length()-i-1),x.second))
                           return true;
                    }
                return false;
                
            }
        }
        return cur->isEnd;
    }
     bool search(string word)
     {
         return tsearch(word,root);
     }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
