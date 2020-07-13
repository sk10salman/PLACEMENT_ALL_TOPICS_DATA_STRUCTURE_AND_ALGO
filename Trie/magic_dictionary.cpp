/*

Implement a magic directory with buildDict, and search methods.

For the method buildDict, you'll be given a list of non-repetitive words to build a dictionary.

For the method search, you'll be given a word, and judge whether if you modify exactly one character into another character in this word, the modified word is in the dictionary you just built.

Example 1:
Input: buildDict(["hello", "leetcode"]), Output: Null
Input: search("hello"), Output: False
Input: search("hhllo"), Output: True
Input: search("hell"), Output: False
Input: search("leetcoded"), Output: False

*/


class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        
    }
    
    /** Build a dictionary through a list of words */
    unordered_map<string,int>m;
    void buildDict(vector<string> dict) {
        for(auto x:dict)
            m[x]=x.length();
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    
    bool check(string s,string w)
    {
        int count=0;
        for(int i=0;i<s.length();i++)
        {
            if(w[i]!=s[i])
                count++;
        }
        if(count==1)
            return true;
        return false;
    }
    bool search(string word) {
        for(auto x:m)
        {
            if(x.second==word.length()&&check(x.first,word))
                return true;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */
