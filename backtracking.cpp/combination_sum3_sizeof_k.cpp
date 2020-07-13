class Solution {
public:
    vector<vector<int>>ans;
    void backtrack(int ar[],int k,int n,vector<int>row,int i)
    {
        if(row.size()==k&&accumulate(row.begin(),row.end(),0)==n)
        {
            ans.push_back(row);
            return;
        }
        if(row.size()>k||i>=9)
            return;
        row.push_back(ar[i]);
        backtrack(ar,k,n,row,i+1);
        row.pop_back();
        backtrack(ar,k,n,row,i+1);
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        int ar[]={1,2,3,4,5,6,7,8,9};
        vector<int>row;
        backtrack(ar,k,n,row,0);
        return ans;
    }
};

/*
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Note:

All numbers will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Example 2:

Input: k = 3, n = 9
Output: [[1,2,6], [1,3,5], [2,3,4]]
