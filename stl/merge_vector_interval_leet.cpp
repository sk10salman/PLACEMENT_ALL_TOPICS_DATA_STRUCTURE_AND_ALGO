 bool cmp(vector<int>&a,vector<int>&b)
    {
        return a[0]<b[0];
    }
class Solution {
public:
   
    vector<vector<int>> merge(vector<vector<int>>& in) {
        if(in.size()<=1)
             return in;
       sort(in.begin(),in.end(),cmp);
        vector<vector<int>>v;
      v.push_back(in[0]);
    for(int i=1;i<in.size();i++)
    {
        vector<int>p(2);
        p[0]=v.back()[0];
        p[1]=v.back()[1];
        
        if(v.back()[1]>=in[i][0])
        {
            if(v.back()[1]<=in[i][1])
            {
                p[1]=in[i][1];
                v.pop_back();
                v.push_back(p);
            }
          
        }
          else
            {
                v.push_back(in[i]);
            }
    }
        return v;
    }
};


/*
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
