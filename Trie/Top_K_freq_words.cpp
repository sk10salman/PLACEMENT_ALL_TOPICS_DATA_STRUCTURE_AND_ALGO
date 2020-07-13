/*

Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words.
    Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:
Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
    with the number of occurrence being 4, 3, 2 and 1 respectively.

*/

bool cmd1(pair<int,string> &a,pair<int,string>&b)
{
    if(a.first==b.first)
        return a.second<b.second;
    return a.first>b.first;
}
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        map<string,int>m;
        for(auto x:words)
            m[x]++;
        vector<pair<int,string>>v;
        for(auto x:m)
        {
            v.push_back({x.second,x.first});
        }
        sort(v.begin(),v.end(),cmd1);
        vector<string>v1;
        for(int i=0;i<k;i++)
            v1.push_back(v[i].second);
        return v1;
    }
};
