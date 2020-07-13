class Solution {
public:
     set<vector<int>>s;
    void solve( vector<vector<int>>&result,int index,vector<int>&row,vector<int>&arr,int sum)
    {
        if(sum==0)
        { 
            s.insert(row);
            return;
        }
        if(sum<0 || index>=arr.size())
            return;
      
        row.push_back(arr[index]);
         solve(result,index+1,row,arr,sum-arr[index]); 
         row.pop_back();
          solve(result,index+1,row,arr,sum);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        vector<vector<int>>result;
        if(arr.size()==0)
             return result;
        vector<int>row;
        sort(arr.begin(),arr.end());
        solve(result,0,row,arr,target);
        for(auto x:s)
            result.push_back(x);
        return result;
    }
};

/*
Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]
*/

