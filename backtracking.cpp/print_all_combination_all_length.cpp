class Solution {
public:
    set<string>s;
    void backtrack(string tiles,int index,string res)
    {
        if(res.size()>=1)
        {
            cout<<res<<" ";
            s.insert(res);
        }
        unordered_set<char>st;
        for(int i=index;i<tiles.length();i++)
        {
            if(st.find(tiles[i])==st.end())
            { res.push_back(tiles[i]);
            swap(tiles[i],tiles[index]);
            
            backtrack(tiles,index+1,res);
            res.pop_back();
            swap(tiles[i],tiles[index]);
             st.insert(tiles[i]);
            }
        }
    }
    int numTilePossibilities(string tiles) {
        if(tiles.length()<=1)
            return tiles.length();
        backtrack(tiles,0,"");
        return s.size();
    }
};

/*
You have a set of tiles, where each tile has one letter tiles[i] printed on it.  Return the number of possible non-empty sequences of letters you can make.

 

Example 1:

Input: "AAB"
Output: 8
Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".
Example 2:

Input: "AAABBC"
Output: 188

print___ 

A AA AAA AAAB AAABB AAABBC AAABC AAABCB AAAC AAACB AAACBB AAB AABA AABAB AABABC AABAC AABACB AABB AABBA AABBAC AABBC AABBCA AABC AABCB AABCBA AABCA AABCAB AAC AACB AACBB AACBBA AACBA AACBAB AACA AACAB AACABB AB ABA ABAA ABAAB ABAABC ABAAC ABAACB ABAB ABABA ABABAC ABABC ABABCA ABAC ABACB ABACBA ABACA ABACAB ABB ABBA ABBAA ABBAAC ABBAC ABBACA ABBC ABBCA ABBCAA ABC ABCA ABCAB ABCABA ABCAA ABCAAB ABCB ABCBA ABCBAA AC ACA ACAB ACABB ACABBA ACABA ACABAB ACAA ACAAB ACAABB ACB ACBA ACBAB ACBABA ACBAA ACBAAB ACBB ACBBA ACBBAA B BA BAA BAAA BAAAB BAAABC BAAAC BAAACB BAAB BAABA BAABAC BAABC BAABCA BAAC BAACB BAACBA BAACA BAACAB BAB BABA BABAA BABAAC BABAC BABACA BABC BABCA BABCAA BAC BACA BACAB BACABA BACAA BACAAB BACB BACBA BACBAA BB BBA BBAA BBAAA BBAAAC BBAAC BBAACA BBAC BBACA BBACAA BBC BBCA BBCAA BBCAAA BC BCA BCAA BCAAB BCAABA BCAAA BCAAAB BCAB BCABA BCABAA BCB BCBA BCBAA BCBAAA C CA CAA CAAB CAABB CAABBA CAABA CAABAB CAAA CAAAB CAAABB CAB CABA CABAB CABABA CABAA CABAAB CABB CABBA CABBAA CB...
