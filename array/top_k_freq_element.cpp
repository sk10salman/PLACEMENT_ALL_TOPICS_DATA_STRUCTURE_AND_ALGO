class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>p;
        map<int,int>mp;
        for(int i=0;i<nums.size();i++)
            mp[nums[i]]++;
        for(auto i=mp.begin();i!=mp.end();i++)
        {
            p.push({i->second,i->first});
        }
        vector<int>v;
        for(int i=0;i<k;i++)
        { v.push_back(p.top().second);
         p.pop();
         }
        reverse(v.begin(),v.end());
        return v;
    }
};


/*
Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
*/
