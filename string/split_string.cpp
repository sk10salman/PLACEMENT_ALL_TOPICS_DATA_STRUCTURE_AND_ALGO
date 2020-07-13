class Solution {
public:
    bool f(string s,string y)
    {
        if(s.length()<y.length())
            return false;
        for(int i=0;i<y.length();i++)
        {
            if(y[i]!=s[i])
                return false;
        }
        return true;
    }
    int isPrefixOfWord(string sentence, string searchWord) {
       
        istringstream ss(sentence); 
       std::string token;
    // Traverse through all words 
    vector<string>v;
	while(std::getline(ss, token, ' ')) {
		v.push_back(token);
		
	}
        for(int i=0;i<v.size();i++)
        {
            if(f(v[i],searchWord))
                return i+1;
        }
        return -1;
    }
};


/*
Input: sentence = "i love eating burger", searchWord = "burg"
Output: 4
Explanation: "burg" is prefix of "burger" which is the 4th word in the sentence.
