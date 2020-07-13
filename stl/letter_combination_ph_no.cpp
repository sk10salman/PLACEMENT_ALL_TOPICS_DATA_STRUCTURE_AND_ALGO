class Solution {
public:
    void lettercmp( vector<string> &result,string digits,string current,int index, vector<string>mapping)
        
    {
        if(index==digits.size())
        {result.push_back(current);
        return;}
        string letter=mapping[digits[index]-'0'];
        for(int i=0;i<letter.length();i++)
            lettercmp(result,digits,current+letter[i],index+1,mapping);
    }
    
    vector<string> letterCombinations(string digits) {
          vector<string>result;
        if(digits.size()<=0)
             return result;
        vector<string>s {"0","0","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
      
        lettercmp(result,digits,"",0,s);
        return result;
    }
};

/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.



Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
