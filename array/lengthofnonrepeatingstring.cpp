int lengthOfLongestSubstring(string s) {
        int a[26];
        memset(a,0,sizeof(a));
        int count=0,sum=0;
        for(int i=0;i<s.length();i++)
        {
            if(a[s[i]-'a']==0)
            {
                a[s[i]-'a']=1;
                count++;
            }
            else
            {
                memset(a,0,sizeof(a));
                count=0;
            }
            sum = max(sum,count);
            
        }
        return sum;
    }
/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

