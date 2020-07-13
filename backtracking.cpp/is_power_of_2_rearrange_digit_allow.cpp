class Solution {
public:
   
    bool reorderedPowerOf2(int N) {
        string s=to_string(N);
        
       if( log2(N)==ceil(log2(N)))
           return true;
      sort(s.begin(),s.end());
        do{
            int x=stoi(s);
                if(s[0]!='0'&& log2(x)==ceil(log2(x)))
                      return true;
        }while(next_permutation(s.begin(),s.end()));
        return false;
    }
};

/*


Example 1:

Input: 1
Output: true
Example 2:

Input: 10
Output: false
Example 3:

Input: 16
Output: true
Example 4:

Input: 24
Output: false
Example 5:

Input: 46
Output: true

